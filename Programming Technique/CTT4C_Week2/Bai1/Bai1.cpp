#include <iostream>
using namespace std;
int main() {
	int var = 10; // (1) -> ok
	// Khai báo biến con trỏ ptr1 và gán bởi địa chỉ biến var.
	int* ptr1 = &var; // (2) => ptr1 -> var
	// Relationship giữa 2 biến ptr1 và biến var; ptr1->var (*)
	*ptr1 = 20; // (3) => var = 20; Do mối quan hệ (*)
	int** ptr2 = &ptr1; // (4) => Relationship ptr2 -> ptr1 (**)
	**ptr2 = 30; // (5) => var = ? và tại sao??
	// Vì (*) và (**) -> ptr2->ptr1->var (***) => var = 30
	int*** ptr3 = &ptr2; // (6) => Relationship ptr3 ->ptr2 (****)
	***ptr3 = 50; // (7) => var = ? và tại sao??
	// Tương tự ta có sơ đồ quan hệ: ptr3 -> ptr2 -> ptr1 -> var (*****) => var = 50
	cout << "\nvar = " << var << endl; // Giá trị biến var
	return 0;
}