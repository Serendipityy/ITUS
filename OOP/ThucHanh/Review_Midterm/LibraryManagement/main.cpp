//#include "Reader.h"
//#include "ChildrenReader.h"
//#include "AdultReader.h"
#include "Library.h"
int main() {
	Library* li = new Library;
	li->input();
	li->print();
	cout << "\n\n\tTONG TIEN LAM THE: " << li->calcTotalRegistCardMoney();
	delete li;
	system("pause");
	return 0;
}