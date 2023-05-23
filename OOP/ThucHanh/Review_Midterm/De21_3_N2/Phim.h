#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Phim {
private:
	char* maSo;
	char* tenPhim;
	char* theLoai;
	char* nhaSX;
	int namSX;
	float xepHang;
public:
	Phim();
	~Phim();
	void Nhap();
	void Xuat();
	char* getTheLoai();
	float getXepHang();
	char* getNhaSX();
	int getNamSX();
	//Phim&operator=(const Phim& p);

	bool operator==(const Phim& other) const;
};