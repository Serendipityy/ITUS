#pragma once
#include "ChildrenReader.h"
#include "AdultReader.h"
#include <iostream>
#include <string>
#include <vector>

class Library {
private:
	// Ke thua
	//vector<ChildrenReader> childList;
	//vector<AdultReader> adultList;

	// Da hinh

	// Khai bao mang 1 chieu chua lop cha - vi co virtual
	// nen no se da hinh sang duoc tung thang con tuong ung
	vector<Reader*> readerList; 
public:
	void input();
	void print();
	int calcTotalRegistCardMoney();
	Library();
	~Library();
};