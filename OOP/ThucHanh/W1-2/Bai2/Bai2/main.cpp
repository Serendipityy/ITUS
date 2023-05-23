#include"list.h"
#include"stack.h"

int main() {
    Stack stack;
    stack.input();
    stack.output();
    cout << "Size: " << stack.size() << endl;
    cout << "Top: " << stack.top() << endl;

    cout << "Stack sau khi pop (lay ra 1 phan tu tren cung): " << endl;
    stack.pop();
    stack.output();
    return 0;
}