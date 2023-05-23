/*****************************************************
* Guide to Read/Write an object from/to file
******************************************************/
#include <iostream>
#include <fstream>
using namespace std;
// Class to define the properties
class Employee {
public:
	string Name;
	int Employee_ID;
	int Salary;
	Employee();
};

// Implement Employee class
Employee::Employee() {
	Name = "abc";
	Employee_ID = 123456;
	Salary = 2000;
}
int main() {
	Employee* Emp_1 = new Employee();
	Emp_1->Name = "Nguyen Chi Thanh";
	Emp_1->Employee_ID = 212121;
	Emp_1->Salary = 11000;
	//Writing this data ‘Emp_1 object’ to file ‘Employee.txt’
	/*ofstream file1;
	file1.open("Employee.txt", ios::out | ios::trunc);*/
	//file1.write((char*)&Emp_1, sizeof(Emp_1));
	//cout << "\nWrite obj_Employee to file successfully!\n";
	//file1.close();
	//Reading data ‘Emp_1 object’ from file ‘Employee.txt’
	ifstream file2;
	file2.open("Employee.txt", ios::in);
	file2.seekg(0);
	file2.read((char*)&Emp_1, sizeof(Emp_1));
	cout << "\nRead obj_Employee from file successfully!\n";
	printf("\nName: % s", Emp_1->Name.c_str());
	printf("\nEmployee ID : % d", Emp_1->Employee_ID);
	printf("\nSalary : % d", Emp_1->Salary);
	file2.close();
	printf("\n-------------------- - End--------------------\n");
	system("pause");
	return 0;
}
/*Write obj_Employee to file successfully!
Read obj_Employee from file successfully!
Name: Nguyen Chi Thanh
Employee ID :212121
Salary :11000
--------------------- End --------------------*/