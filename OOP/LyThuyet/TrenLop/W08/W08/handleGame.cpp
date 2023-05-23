
#include "HandleGame.h"
#include "Prince.h"
#include "AcademicGate.h"
#include "PowerGate.h"
#include "BusinessGate.h"

HandleGame::HandleGame()
{
	x = new Gate * [1000];
	n = 0;
}


HandleGame::~HandleGame()
{
	delete[]x;
}

void HandleGame::inputGate()
{
	int k;
	for (int i = 0;; i++)
	{
		do {
			cout << "\nloai congn: \n1- Giao Thuong \n2-Hoc Thuat \n3-Suc Manh \n0-ket thuc\n";
			cin >> k;
			if (k != 1 && k != 2 && k != 0 && k != 3) cout << "\nkhong hop le!\n";
		} while (k != 1 && k != 2 && k != 0 && k != 3);
		if (k == 0) return;
		else if (k == 1)
		{
			typeGate[n] = k;
			n++;
			x[i] = new BusinessGate;
			x[i]->input();
		}
		else if (k == 2)
		{
			typeGate[n] = k;
			n++;
			x[i] = new AcademicGate;
			x[i]->input();
		}
		else
		{
			typeGate[n] = k;
			n++;
			x[i] = new PowerGate;
			x[i]->input();
		}
	}
}

void HandleGame::printGate()
{
	cout << "so cong = " << n << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		x[i]->print();
		cout << endl;
	}
}

//bool HandleGame::handleCondition()
//{
//	X.input();
//	for (int i = 0; i < n; i++)
//	{
//		if (typeGate[i] == 1)
//			X.money -= x[i]->condition();
//		if (typeGate[i] == 2)
//		{
//			if (X.intellectual < x[i]->condition()) return false;
//		}
//		if (typeGate[i] == 3)
//			X.power -= x[i]->condition();
//	}
//	if (X.money >= 0 && X.power >= 0) return true;
//	else return false;
//}

void HandleGame::handleCondition()
{
	X.input();

	int i = 0;
	for (int i=0; i <n; i++)
	{
		if (typeGate[i] == 1) {
			X.money -= x[i]->condition();
			if (X.money < 0) {
				cout << "Hoang tu da sml o cong " << i + 1;
				break;
			}
			else {
				cout << "Hoang tu da vuot qua cong giao thuong [" << i + 1 << "]" << endl;
				cout << "Thong so hien tai [" << X.money << ", " << X.intellectual << ", " << X.power << "]" << endl;
			}
		}
		if (typeGate[i] == 2)
		{
			if (x[i]->condition() > X.intellectual) {
				cout << "Hoang tu da sml o cong " << i + 1;
				break;
			}
			else {
				cout << "Hoang tu da vuot qua cong tri tue [" << i + 1 << "]" << endl;
			}
		}
		if (typeGate[i] == 3) {
			X.power -= x[i]->condition();
			if (X.power < 0) {
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
		cout << "Thong so hien tai [" << X.money << ", " << X.intellectual << ", " << X.power << "]" << endl;

		i++;
	}
}