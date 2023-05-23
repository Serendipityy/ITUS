#pragma once
#include<iostream>
#include<string>
using namespace std;

// Class definition (.h)
class Cat {
private: // data / Attribute / backup fields
	float _weight;
	float _height;
	// Nếu muốn giấu một hàm nào đó thì cho vô private
	// nhưng nó vẫn sẽ truy cập nội bộ được trong cách hàm khác
	// void _tinhtoansieucap();
	string _name;

public: // getter / setter ==> Property
// Tên hàm luôn bắt đầu bằng động từ
// Nếu là danh từ thì hiểu là nó cung cấp thuộc tính nào đó
	// Getters
	float getWeight() {
		return _weight;
	}
	float getHeight() {
		return _height;
	}
	string getName() {
		return _name;
	}


	// Setters
	void setWeight(float value) {
		_weight = value;
	}
	void setHeight(float value) {
		_height = value;
	}
	void setName(string value) {
		_name = value;
	}
public: 
	// Constructor (Hàm tạo)
	// Non-parameter constructor (hàm tạo không có đối số)
	Cat() { 
		_name = "";
		_height = 0;
		_weight = 0;
	}

	// Paramerized constructor (hàm tạo có đối số)
	Cat(string name, float weight, float height) {
		_name = name;
		_weight = weight;
		_height = height;
	}


	// Destructor (Hàm hủy)
	// Hàm hủy tự động được gọi khi đối tượng bị thu hồi vùng nhớ
	~Cat() {
		cout << "Destructor" << endl;
	}

public: // behaviors / method
	void eat();
	void run();
	void sleep();

};