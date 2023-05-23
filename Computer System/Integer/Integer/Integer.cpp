#include <iostream>
#include<string>
#include<cmath>
#include<limits>
using namespace std;

// 1, 2.

// Hàm nhập vào số nguyên 16 bit
void inputSignedInteger(int& x) {
    while (true) {
        cout << "Nhap vao mot so nguyen 16 bit, trong doan [-32768, 32767]: ";
        cin >> x;
        if (cin.fail() || cin.peek() != '\n' ) { // Kiểm tra đầu vào có phải là số nguyên hay không
            cout << "Gia tri ban nhap khong hop le! Vui long nhap lai." << endl;
            cin.clear(); // Xóa bộ đệm đầu vào
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua tất cả các ký tự đầu vào còn lại trên dòng
            continue; // Quay lại vòng lặp để nhập lại giá trị
        }
        if ((x < -32768) || (x > 32767)) {
            cout << "Gia tri ban nhap khong hop le! Vui long nhap lai." << endl;
        }
        else {
            break;
        }
    }
}

// Hàm chuyển đổi số nguyên sang dạng binary
void convertToBinary(int x) {
    cout << "Dang nhi phan cua " << x << " la: ";
    for (int i = 15; i >= 0; i--) {
        // Dịch bit của số nguyên x để lấy giá trị của từng bit
        // rồi trích xuất giá trị của bit
        int bit = (x >> i) & 1;
        cout << bit;
    }
    cout << endl;
}

// Hàm chuyển đổi số nguyên về dạng bù 2
void printTwosComplement(int x) {
    cout << "Dang bu 2 cua " << x << " la: ";
    // Đảo bit rồi cộng 1 để chuyển sang dạng bù 2
    x = ~x + 1;
    for (int i = 15; i >= 0; i--) {
        int bit = (x >> i) & 1;
        cout << bit;
    }
    cout << endl;
}


// 3, 4.

// Hàm in ra binary bit pattern của một số single precision
void printBinaryBitPattern(float Y) {
    // Chuyển đổi định dạng số thực sang dạng nhị phân
    unsigned int binaryRep = *(unsigned int*)&Y;

    // In ra bit pattern
    cout << "Binary bit pattern cua Y: ";
    for (int i = 31; i >= 0; i--) {
        if ((binaryRep >> i) & 1) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << endl;
}

void inputSinglePrecision(float& y) {
    bool invalid = true;
    do {
        cout << "Nhap vao mot so single precision Y: ";
        cin >> y;
        if (cin.fail() || cin.peek() != '\n' || isnan(y) || isinf(y)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Gia tri ban nhap khong hop le! Vui long nhap lai." << endl;
        }
        else {
            float temp = stof(to_string(y));
            if (temp != y) {
                cout << "Gia tri ban nhap khong hop le! Vui long nhap lai." << endl;
            }
            else {
                invalid = false;
            }
        }
    } while (invalid);
}
int main() {
    
    cout << "------ *Cau 1, 2* ------" << endl;
    int x;
    inputSignedInteger(x);
    convertToBinary(x);
    printTwosComplement(x);

    cout << "\n------ *Cau 3, 4* ------" << endl;
    float y;
    inputSinglePrecision(y);
    printBinaryBitPattern(y);

    return 0;
}