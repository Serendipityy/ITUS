#include "Date.h"

Date::Date() {
	day = month = year = 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

istream& operator>>(istream& is, Date& d) {
	is >> d.day >> d.month >> d.year;
	return is;
}

ostream& operator<<(ostream& os, const Date& d) {
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}

bool Date::operator>(const Date& d) const {
	if (year > d.year) return true;
	else if (year == d.year && month > d.month) return true;
	else if (year == d.year && month == d.month && day > d.day) return true;
	return false;
}