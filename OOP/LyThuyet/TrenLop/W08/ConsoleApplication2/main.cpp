#include <iostream>
#include "Gate.h"
#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"

int main() {
	cout << "1. Cong giao thuong " << endl;
	cout << "2. Cong hoc thuat" << endl;
	cout << "3. Cong suc manh" << endl;
	cout << "Nhap so luong cong: ";
	int n; cin >> n;
	Gate* arr[1000];

	for (int i = 0; i < n; i++) {
		cout << "Nhap loai cong (1, 2 hoac 3): ";
		int type; cin >> type;
		if (type == 1) arr[i] = new BusinessGate();
		if (type == 2) arr[i] = new AcademicGate();
		if (type == 3) arr[i] = new PowerGate();
		arr[i]->input();
	}

	int money, intellectual, power;
	cout << "[Nhap thong so cua hoang tu]" << endl;
	cout << "Nhap so tien cua hoang tu: "; cin >> money;
	cout << "Nhap tri tue cua hoang tu: "; cin >> intellectual;
	cout << "Nhap suc manh cua hoang tu: "; cin >> power;

	int i = 0;
	while (money > 0 && intellectual > 0 && power > 0 && i < n)
	{
		if (arr[i]->getType() == 1) {
			money -= arr[i]->feature();
			if (money < 0) {
				cout << "Hoang tu da sml o cong " << i + 1;
				break;
			}
			else {
				cout << "Hoang tu da vuot qua cong giao thuong [" << i + 1 << "]" << endl;
				cout << "Thong so hien tai [" << money << ", " << intellectual << ", " << power << "]" << endl;
			}
		}
		if (arr[i]->getType() == 2)
		{
			if (arr[i]->feature() > intellectual) {
				cout << "Hoang tu da sml o cong " << i + 1;
				break;
			}
			else {
				cout << "Hoang tu da vuot qua cong tri tue [" << i + 1 << "]" << endl;
			}
		}
		if (arr[i]->getType() == 3) {
			power -= arr[i]->feature();
			if (power < 0) {
				cout << "Hoang tu da sml o cong " << i + 1;
				break;
			}
			else {
				cout << "Hoang tu da vuot qua cong suc manh [" << i + 1 << "]" << endl;
			}
		}
		if (i == n - 1) {
			cout << "Hoang tu da giai cuu duoc cong chua" << endl;
			break;
		}
		cout << "Thong so hien tai [" << money << ", " << intellectual << ", " << power << "]" << endl;

		i++;
	}

}
