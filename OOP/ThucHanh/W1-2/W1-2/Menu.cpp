#include"Stack.h"

void menu() {
	bool quit = false;
	int choosen;

	Stack stk(SIZE);
	do {
		system("cls");
		cout << "---------- *CLASS STACK* ------------" << endl;
		cout << "1. Them phan tu vao stack." << endl;
		cout << "2. Lay phan tu ra khoi stack." << endl;
		cout << "3. Kich thuoc cua stack." << endl;
		cout << "4. Top element cua stack." << endl;
		cout << "5. In ra cac phan tu trong stack. " << endl;
		cout << "0. Exit." << endl;
		cout << "------------------------------------" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> choosen;
		switch (choosen) {
		case 1: {
			stk.input();
			system("pause");
		}
		break;
		case 2:
		{
			stk.pop();
			system("pause");
		}
		break;
		case 3:
		{
			cout<<"Kich thuoc cua stack la "<< stk.size();
			system("pause");
		}
		break;
		case 4:
		{
			cout<<"Top element cua stack la "<< stk.peek();
			system("pause");
		}
		break;
		case 5:
		{
			stk.output();
			system("pause");
		}
		break;
		default: {
			cout << "Lua chon khong hop le";
			system("pause");
		}
			   break;
		}

	} while (!quit);
}