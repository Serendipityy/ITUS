#include "Designer.h"
#include "Employee.h"

// Doc nhung thuoc tinh rieng (o lop con)
void Designer::readFile(ifstream& filein) {
	Employee::readFile(filein);
	filein >> bonusSalary;
}

void Designer::printFromFile() {
	Employee::printFromFile();
	cout << "\nTien thuong: " <<fixed<<setprecision(0) << bonusSalary;
}