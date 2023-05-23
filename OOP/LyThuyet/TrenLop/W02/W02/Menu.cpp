#include "bookManagement.h"

void menu() {
	BookStore store;
	Seller s;
	int choosen;
	bool quit = false;
	do {
		system("cls");
		cout << "------------ *BOOK MANAGEMENT* -------------" << endl;
		cout << "0. Doc thong tin danh sach sach tu file txt" << endl;
		cout << "1. Xuat danh sach sach" << endl;
		cout << "2. Danh sach sach sap xep theo gia ban " << endl;
		cout << "3. Danh sach top Ka sach moi nhat" << endl;
		cout << "4. Nhap sach" << endl;
		cout << "5. Them sach vao gio hang" << endl;
		cout << "6. Thanh toan" << endl;
		cout << "7. Danh sach cac sach sap het hang" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Nhap lua chon: "; cin >> choosen;
		switch (choosen) {
		case 0: {
			store.loadData("BookManagement.txt");
			cout << "Da doc thanh cong thong tin tu file.Nhap 1 de xuat ra danh sach sach!" << endl;
			system("pause");
		}
		break;
		case 1:
		{
			store.printData();
			system("pause");
		}
		break;
		case 2:
		{
			store.sortData();
			cout << "Da sap xep danh sach sach theo gia ban. Nhap 1 de xem.";
			system("pause");
		}
		break;
		case 3:
		{
			store.getTopKa();
			cout << "Da lay ra top Ka. Nhap 1 de xem." << endl;
			system("pause");
		}
		break;
		case 4:
		{
			store.addBook();
			system("pause");
		}
		break;
		case 5:
		{
			string isbn;
			cout << "\nNhap ma sach (ISBN) can them: "; 
			cin.ignore();
			getline(cin, isbn);
			s.sellBook(store, isbn);
			system("pause");
		}
		break;
		case 6:
		{
			Book book1;
			book1.setISBN("52013142525");
			book1.setTitle("Natural language processing");
			book1.setAuthor("Shunyu Yao");
			book1.setLanguage("Chinese");
			book1.setPublishedYear(2020);
			book1.setPrice(199900);
			book1.setStockLevel(96);
			DateTime inputDate1;
			inputDate1.setYear(2022);
			inputDate1.setMonth(6);
			inputDate1.setDay(6);
			inputDate1.setHour(9);
			inputDate1.setMinute(0);
			inputDate1.setSecond(0);
			book1.setInputDate(inputDate1);

			Book book2;
			book2.setISBN("25251325");
			book2.setTitle("Javascript Basic");
			book2.setAuthor("Edward Tian");
			book2.setLanguage("English");
			book2.setPublishedYear(2019);
			book2.setPrice(250500);
			book2.setStockLevel(10);
			DateTime inputDate2;
			inputDate2.setYear(2023);
			inputDate2.setMonth(1);
			inputDate2.setDay(1);
			inputDate2.setHour(12);
			inputDate2.setMinute(5);
			inputDate2.setSecond(0);
			book2.setInputDate(inputDate2);

			// Tạo đơn hàng với những quyển sách muốn thêm
			vector<Book> books = { book1, book2 };
			store.createOrder("Meiko", books);
			system("pause");
		}
		break;
		case 7:
		{
			cout << "-------DANH SACH NHUNG QUYEN SACH SAP HET HANG--------" << endl;
			store.printRunningOutBooks();
			system("pause");
		}
		break;
		default:
		{
			cout << "Lua chon cua ban khong hop le!";
			system("pause");
		}
		break;
		}
	} while (!quit);
}