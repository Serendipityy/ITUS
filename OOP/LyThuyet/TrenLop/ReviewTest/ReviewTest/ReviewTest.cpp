#pragma warning(disable : 4996)
#include<iostream>
#include<cstring> // for strlen() and strcpy() functions
using namespace std;

class MyString
{
public:
    MyString(const char* str = "") // constructor
    {
        pStr = new char[strlen(str) + 1];
        strcpy(pStr, str);
    }

    MyString(const MyString& other) {
        pStr = new char[strlen(other.pStr) + 1]; //allocate memory for the string
        strcpy(pStr, other.pStr); //copy the string to the allocated memory
    }

    MyString operator+(const MyString& str) // overloaded + operator
    {
        if (this == &str) {
            return* this;
        }
        else {
            char* temp = new char[strlen(pStr) + strlen(str.pStr) + 2];
            strcpy(temp, pStr);
            strcat(temp, " ");
            strcat(temp, str.pStr);
            MyString result(temp);
            delete[] temp;
            return result;
        }   
    }

    friend ostream& operator<<(ostream& os, const MyString& str) // overloaded << operator
    {
        os << str.pStr;
        return os;
    }
    ~MyString() {
        delete[] pStr; //free the memory allocated for the string
        pStr = NULL;
    }

private:
    char* pStr; // to store the string
};

int main() {
    char s1[] = "Hello";
    char s2[] = "John!";
    MyString a(s1), b(s2); // a="Hello", b="John!"
    MyString c = a + b; // c will be "Hello John!"
    cout << "This is my string: " << c << endl;
    return 0;
}
