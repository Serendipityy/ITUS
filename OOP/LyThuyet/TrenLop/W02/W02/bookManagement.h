#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<ctime>
#include<iomanip>
#pragma warning(disable : 4996)
using namespace std;

class DateTime {
private:
	int year, month, day, hour, minute, second;
public:
	// Bổ sung:
	// Hàm để lấy ra thời gian hiện tại trên hệ thống
	DateTime currentDateTime() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		int year = ltm->tm_year + 1900;
		int month = ltm->tm_mon + 1;
		int day = ltm->tm_mday;
		int hour = ltm->tm_hour;
		int minute = ltm->tm_min;
		int second = ltm->tm_sec;
		DateTime dt;
		dt.setYear(year);
		dt.setMonth(month);
		dt.setDay(day);
		dt.setHour(hour);
		dt.setMinute(minute);
		dt.setSecond(second);
		return dt;
	}
public:
	// Getters
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

	// Setters
	void setYear(int _year) { year = _year; }
	void setMonth(int _month) { month = _month; }
	void setDay(int _day) { day = _day; }
	void setHour(int _hour) { hour = _hour; }
	void setMinute(int _minute) { minute = _minute; }
	void setSecond(int _second) { second = _second; }

public:
	void printDateTime() {
		cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
	}
	// Nạp chồng toán tử: so sánh thời gian
	bool operator>(const DateTime&);
};


class Book {
private:
	string ISBN, title, author, language;
	int publishedYear, stockLevel;
	double price;
	DateTime inputDate;
public:
	// Getters
	string getISBN() { return ISBN; }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getLanguage() { return language; }
	int getPublishedYear() { return publishedYear; }
	double getPrice() { return price; }
	int getStockLevel() { return stockLevel; }
	DateTime getInputDate() { return inputDate; }

	// Setters
	void setISBN(string _ISBN) { ISBN = _ISBN;  }
	void setTitle(string _title) { title = _title; }
	void setAuthor(string _author) { author = _author; }
	void setLanguage(string _language) { language = _language; }
	void setPublishedYear(int _publishedYear) { publishedYear = _publishedYear; }
	void setPrice(double _price) { price = _price; }
	void setStockLevel(int _stockLevel) { stockLevel = _stockLevel; }
	void setInputDate(DateTime _inputDate) { inputDate = _inputDate; }

public:
	// Bổ sung: 
	// Các hàm tăng / giảm stock level
	void increaseStockLevel(int amount) {
		stockLevel += amount;
	}
	void decreaseStockLevel() {
		if (stockLevel > 0) {
			stockLevel--;
		}
	}

	// Lấy thông tin sách từ file
	void getBookFromFile(ifstream&);

	// Kiểm tra xem sách có sắp hết hàng không
	bool isRunningOut() {
		return stockLevel < 50;
	}

	// In ra thông tin sách
	void printBook();
};


class BookStore {
private:
	string name;
	vector<Book> data;
public:
	// Getters
	string getName() {
		return name;
	}
	vector<Book> GetData() { return data; }

	// Setters
	void setName(string _name) {
		name = _name;
	}
	void setData(vector<Book>_data) { data = _data; }


public:
	// Chỉnh sửa:
	// Các hàm này được đưa qua lớp BookStore
	void loadData(string);
	void sortData();
	void printData();
	void addBook();
	void createOrder(const string&, vector<Book>&);

public:
	// Lấy ra top Ka tính theo ngày nhập
	vector <Book>getTopKa(int K = 10) {
		vector<Book> topBooks;

		// Sắp xếp sách theo ngày nhập (mới nhất trên cùng)
		sort(data.begin(), data.end(), [](Book a, Book b) {
			return a.getInputDate() > b.getInputDate();
			});

		// Lấy ra top Ka 
		for (int i = 0; i < K && i < data.size(); i++) {
			topBooks.push_back(data[i]);
		}

		return topBooks;
	}

	//DateTime currentDateTime();

	// Lấy ra thông tin danh sách sách
	vector<Book> getBooks() const {
		return data;
	}

	// Đọc danh sách sách từ file
	void readDataFromFile(string);

	// In ra danh sách các sách sắp hết hàng
	void printRunningOutBooks();
};

// Bổ sung:
// class Seller: 
// Dùng để lưu trữ thông tin về giỏ hàng, bán sách,...
class Seller {
public:
	void sellBook(BookStore&, string);
};
class Order {
private:
	string customerName;
	Book bookInfo;
	DateTime salesTime;
public:
	void setCustomerName(string name) {
		customerName = name;
	}
	void setBookInfo(Book b) {
		bookInfo = b;
	}
public:
	void saveOrderToFile();
};

void menu();