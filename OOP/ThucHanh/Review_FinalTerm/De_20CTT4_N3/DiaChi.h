#ifndef DIACHI_H
#define DIACHI_H

#include "NgayGD.h"

class DiaChi
{
private:
	char* soNha;
	char* tenDuong;
	char* phuong;
	char* quan;
	char* tp;
public:
	DiaChi();
	DiaChi(char* _soNha, char* _tenDuong, char* _phuong, char* _quan, char* _tp);
	DiaChi(const DiaChi& other);
	~DiaChi();
	void nhapDC();
	void xuatDC();
};

#endif // !DIACHI_H

