#include "ChildrenReader.h"

ChildrenReader::ChildrenReader() {

}

ChildrenReader::~ChildrenReader() {

}

void ChildrenReader::input() {
	Reader::input();
	cout << "Nhap ten nguoi dai dien: ";
	cin.ignore();
	getline(cin, representativeName);
}

void ChildrenReader::print() {
	Reader::print();
	cout << "Ten nguoi dai dien: " << representativeName;
}

int ChildrenReader::calcRegistCardMoney() {
	return validMonth * 5000;
}

