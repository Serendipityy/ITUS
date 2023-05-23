#ifndef NGAYGD_H
#define NGAYGD_H


#pragma once
#pragma warning(disable:4996)

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class NgayGD
{
private:
	int ngay, thang, nam;
public:
	NgayGD();
	NgayGD(int _ngay, int _thang, int _nam);
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int _ngay);
	void setThang(int _thang);
	void setNam(int _nam);
	void nhapNgayGD();
	void xuatNgayGD();

};


#endif // !NGAYGD_H

