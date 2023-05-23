#include "Programmer.h"
#include "Employee.h"

// Doc nhung thuoc tinh rieng (o lop con)
void Programmer::readFile(ifstream& filein) {
	Employee::readFile(filein);
	filein >> overtimeSalary;
}

void Programmer::printFromFile() {
	Employee::printFromFile();
	cout << "\nTien lam ngoai gio: " << fixed << setprecision(0) << overtimeSalary;
}