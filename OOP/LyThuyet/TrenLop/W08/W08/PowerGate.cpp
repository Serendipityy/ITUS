#include "PowerGate.h"



PowerGate::PowerGate()
{
}


PowerGate::~PowerGate()
{
}

void PowerGate::input()
{
	cout << "Nhap suc manh dung si: "; 
	cin >> power;
}

void PowerGate::print()
{
	cout << "Suc manh dung si la: " << power << endl;
}

int PowerGate::condition()
{
	return power;
}
