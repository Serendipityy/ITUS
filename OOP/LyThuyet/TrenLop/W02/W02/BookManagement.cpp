#include "bookManagement.h"

// So sánh thời gian
bool DateTime::operator>(const DateTime& other) {
	if (year > other.year) return true;
	else if (year < other.year) return false;
	else {
		if (month > other.month) return true;
		else if (month < other.month) return false;
		else {
			if (day > other.day) return true;
			else if (day < other.day) return false;
			else {
				if (hour > other.hour) return true;
				else if (hour < other.hour) return false;
				else {
					if (minute > other.minute) return true;
					else if (minute < other.minute) return false;
					else {
						if (second > other.second) return true;
						else return false;
					}
				}
			}
		}
	}
}
void Book::getBookFromFile(ifstream& file) {
	getline(file, ISBN);
	getline(file, title);
	getline(file, author);
	getline(file, language);
	file >> publishedYear >> price >> stockLevel;
	inputDate.setYear(0);
	inputDate.setMonth(0);
	inputDate.setDay(0);
	inputDate.setHour(0);
	inputDate.setMinute(0);
	inputDate.setSecond(0);
	file.ignore();
}

void Book::printBook() {
	cout << "ISBN: " << ISBN << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Language: " << language << endl;
	cout << "Published Year: " << publishedYear << endl;
	cout << "Price: " << price << endl;
	cout << "Stock Level: " << stockLevel << endl;
	cout << "Input Date: ";
	inputDate.printDateTime();
	cout << endl;
}
// Load thông tin sách
void BookStore::loadData(string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Loi: Khong the doc duoc file " << filename << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		// Tách dòng thành các trường được phân tách bằng dấu ',
		vector<string> fields;
		size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != string::npos) {
			fields.push_back(line.substr(start, end - start));
			start = end + 1;
		}
		fields.push_back(line.substr(start));

		// Tạo ra một đối tượng Book và thiết lập thuộc tính cho nó
		Book book;
		book.setISBN(fields[0]);
		book.setTitle(fields[1]);
		book.setAuthor(fields[2]);
		book.setLanguage(fields[3]);
		book.setPublishedYear(stoi(fields[4]));
		book.setPrice(stof(fields[5]));
		book.setStockLevel(stoi(fields[6]));
		DateTime inputDate;
		inputDate.setYear(stoi(fields[7]));
		inputDate.setMonth(stoi(fields[8]));
		inputDate.setDay(stoi(fields[9]));
		inputDate.setHour(stoi(fields[10]));
		inputDate.setMinute(stoi(fields[11]));
		inputDate.setSecond(stoi(fields[12]));
		book.setInputDate(inputDate);

		// Thêm sách vào vector lưu trữ danh sách
		data.push_back(book);
	}

	file.close();
}

// Sắp xếp sách theo giá bán, nếu trùng thì sắp theo tên
void BookStore::sortData() {
	sort(data.begin(), data.end(), [](Book a, Book b) {
		if (a.getPrice() == b.getPrice()) {
			return a.getTitle() < b.getTitle();
		}
		else {
			return a.getPrice() < b.getPrice();
		}
	});
}

// Xuất ra danh sách sách
void BookStore::printData() {
	for (Book &book : data) {
		cout << "\nMa sach: " << book.getISBN() << endl;
		cout << "Ten sach: " << book.getTitle() << endl;
		cout << "Ten tac gia: " << book.getAuthor() << endl;
		cout << "Ngon ngu cua sach: " << book.getLanguage() << endl;
		cout << "Nam xuat ban: " << book.getPublishedYear() << endl;
		cout << "Gia ban: " << book.getPrice() <<" VND" << endl;
		cout << "So luong sach hien co: " << book.getStockLevel() << endl;
		cout<<"Ngay nhap sach: " << book.getInputDate().getYear() << "/ "
			<< book.getInputDate().getMonth() << "/ "
			<< book.getInputDate().getDay() << " "
			<< book.getInputDate().getHour() << ":"
			<< book.getInputDate().getMinute() << ":"
			<< book.getInputDate().getSecond() << endl;
	}
}

// Nhập sách, thêm sách vào danh sách sách nếu chưa có
void BookStore::addBook() {
	string isbn, title, author, language;
	int year, stockLevel;
	double price;

	cout << "Nhap ma sach (ISBN): ";
	cin.ignore();
	getline(cin, isbn);
	cout << "Nhap ten sach: ";
	getline(cin, title);
	cout << "Nhap tac gia: ";
	getline(cin, author);
	cout << "Nhap ngon ngu sach: ";
	getline(cin, language);
	cout << "Nhap nam xuat ban: ";
	cin >> year;
	cout << "Nhap gia ban: ";
	cin >> price;
	cout << "Nhap so luong sach hien co trong nha sach: ";
	cin >> stockLevel;

	// Kiểm tra sách đã có trong danh sách chưa
	for (auto& book : data) {
		if (book.getISBN() == isbn) {
			cout << "Sach da co trong danh sach. Tang so luong stock level..." << endl;
			book.increaseStockLevel(stockLevel);
			DateTime current = DateTime();
			book.setInputDate(current.currentDateTime());
			return;
		}
	}

	// Thêm sách mới vào danh sách
	Book newBook;
	newBook.setISBN(isbn);
	newBook.setTitle(title);
	newBook.setAuthor(author);
	newBook.setLanguage(language);
	newBook.setPublishedYear(year);
	newBook.setPrice(price);
	newBook.setStockLevel(stockLevel);
	DateTime current = DateTime();
	newBook.setInputDate(current.currentDateTime());
	data.push_back(newBook);
	cout << "Da them sach vao danh sach!" << endl;
}


// Thêm sách vào giỏ hàng
void Seller::sellBook(BookStore& store, string isbn) {
	bool foundBook = false;
	vector<Book> books = store.getBooks();

	// Tìm sách với mã ISBN
	for (auto& book : books) {
		if (book.getISBN() == isbn) {
			foundBook = true;
			int stockLevel = book.getStockLevel();

			// Kiểm tra có còn đủ sách trong stock để bán
			if (stockLevel > 0) {
				book.setStockLevel(stockLevel - 1);
				cout << "Da them sach vao gio hang!" << endl;
			}
			else {
				cout << "Sach nay khong con hang!" << endl;
			}
			break;
		}
	}

	if (!foundBook) {
		cout << "Khong tim thay sach co ma ISBN " << isbn << endl;
	}
}

void BookStore::readDataFromFile(string fileName) {
	ifstream file(fileName);
	if (file.is_open()) {
		while (!file.eof()) {
			Book b;
			b.getBookFromFile(file);
			data.push_back(b);
		}
		file.close();
	}
}

// Tạo đơn hàng và ghi vào file
void BookStore::createOrder(const string& customerName, vector<Book>& books) {
	// Lấy ra thời gian hiện tại trên hệ thống
	std::time_t now = std::time(nullptr);

	// Đọc nội dung của file và lưu vào vector
	// Ghi đơn hàng mới lên đầu vector
	ifstream fin("orders.txt");
	vector<string> lines;
	if (fin.is_open()) {
		string line;
		while (getline(fin, line)) {
			lines.push_back(line);
		}
		fin.close();
	}
	else {
		cout << "Loi: Khong the mo file orders." << endl;
		return;
	}

	// Mở lại file và ghi nội dung lên file
	ofstream fout("orders.txt");
	if (fout.is_open()) {
		fout << "Ten khach hang: " << customerName << endl;
		fout << "Thoi gian dat hang: " << std::put_time(std::localtime(&now), "%c") << std::endl;
		fout << "------------------------------" << endl;
		for (auto& book : books) {
			fout << "Ma sach (ISBN): " << book.getISBN() << endl;
			fout << "Ten sach: " << book.getTitle() << endl;
			fout << "Tac gia: " << book.getAuthor() << endl;
			fout << "Ngon ngu: " << book.getLanguage() << endl;
			fout << "Nam xuat ban: " << book.getPublishedYear() << endl;
			fout << "Gia ban: " << book.getPrice() << endl;
			fout << "So luong sach hien co: " << book.getStockLevel() << endl;
			fout << "Ngay nhap: " << book.getInputDate().getYear() << "-" << book.getInputDate().getMonth() << "-"
				<< book.getInputDate().getDay() << " " << book.getInputDate().getHour() << ":"
				<< book.getInputDate().getMinute() << ":" << book.getInputDate().getSecond() << endl;
			fout << endl;
		}
		fout << endl;
		for (auto& line : lines) {
			fout << line << endl;
		}
		fout.close();
		cout << "Da tao thanh cong don hang." << endl;
	}
	else {
		cout << "Loi: Khong the mo file orders." << endl;
	}
};

void BookStore::printRunningOutBooks() {
	cout << "Danh sach nhung quyen sach sap het hang:" << endl;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].isRunningOut()) {
			data[i].printBook();
		}
	}
}