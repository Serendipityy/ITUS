#include "AdultReader.h"

AdultReader::AdultReader() {

}

AdultReader::~AdultReader() {

}

void AdultReader::input() {
	Reader::input();
	cout << "Nhap CMND: ";
	cin.ignore();
	getline(cin, identityCard);
}

void AdultReader::print() {
	Reader::print();
	cout << "CMND: " << identityCard;
}

int AdultReader::calcRegistCardMoney() {
	return validMonth * 10000;
}