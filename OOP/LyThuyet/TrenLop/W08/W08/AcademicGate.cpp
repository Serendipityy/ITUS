#include "AcademicGate.h"


AcademicGate::AcademicGate()
{
}


AcademicGate::~AcademicGate()
{
}

void AcademicGate::input()
{
	Gate::input();
	cout << "Nhap tri tue cau hoi: ";
	cin >> intellectual;
}

void AcademicGate::print()
{
	Gate::print();
	cout << "Tri tue cau hoi: " << intellectual << endl;
}

int AcademicGate::condition()
{
	return intellectual;
}

