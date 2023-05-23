#pragma once
#include <iostream>
#include <string>
using namespace std;

class Reader { // Lop cha
protected:
	string name;
	string registCardDate; // ngay dang ky the (dd/mm/yyyy)
	int validMonth; // so thang co hieu luc cua the doc gia
	bool checkGender; // true: tre em, false: nguoi lon
public:
	Reader();
	~Reader();

	//void input(); 
	//void print();

	virtual void input(); // phuong thuc ao - nhap thong tin doc gia
	virtual void print(); // phuong thuc ao - xuat thong tin doc gia
	// Khai bao phuong thuc thuan ao - cac lop con ke thua se di dinh nghia
	virtual int calcRegistCardMoney() = 0;

	bool getCheckGender() {
		return checkGender;
	}
	void setCheckGender(bool _checkGender) {
		checkGender = _checkGender;
	}
};