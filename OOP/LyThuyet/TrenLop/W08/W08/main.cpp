#include <iostream>
#include "Gate.h"
#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"
#include "HandleGame.h"

int main()
{
	HandleGame x;
	x.inputGate();
	x.printGate();
	//if (x.handleCondition() == true) cout << "Cuu duoc cong chua ^^" << endl;
	//else cout << "Hoang tu sml :D" << endl;
	x.handleCondition();
	system("pause");
	return 0;
}
