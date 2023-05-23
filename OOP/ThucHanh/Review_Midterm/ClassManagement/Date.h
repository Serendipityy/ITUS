#pragma once
#include<iostream>
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);
	friend istream& operator>>(istream& is, Date& d);
	friend ostream& operator<<(ostream& os, const Date& d);
	bool operator>(const Date& d) const;
};


