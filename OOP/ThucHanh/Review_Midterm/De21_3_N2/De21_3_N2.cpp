﻿//#include<iostream>
//using namespace std;
//class ComplexNum {
//private:
//	float m_Real;
//	float m_Img;
//public:
//	ComplexNum() {
//		m_Real = 0;
//		m_Img = 0;
//	}
//	ComplexNum(float real, float img = 0) {
//		m_Real = real;
//		m_Img = img;
//	}
//	virtual ~ComplexNum() {
//		cout << m_Real << "," << m_Img << endl;
//	}
//};
//
//int main() {
//	ComplexNum x(1, 9); //L1
//	ComplexNum y(5); //L2
//	ComplexNum* p; //L3
//	p = new ComplexNum(11, 13); //L4
//	delete p; //L5
//	p = &x; //L6
//	return 0;
//}

// a) Giải thích các lệnh từ L1 tới L6 làm gì
/*
L1: Tạo đối tượng phức có phần thực bằng 1 và phần ảo bằng 9 và gán cho biến x.
L2: Tạo đối tượng phức có phần thực bằng 5 và phần ảo bằng 0 và gán cho biến y.
L3: Khai báo con trỏ kiểu ComplexNum tên là p.
L4: Cấp phát bộ nhớ động để tạo một đối tượng phức có phần thực bằng 11 và phần ảo bằng 13 và gán địa chỉ của đối tượng này cho con trỏ p.
L5: Giải phóng bộ nhớ đã được cấp phát trước đó cho đối tượng phức mà con trỏ p đang trỏ đến.
L6: Gán địa chỉ của đối tượng phức x cho con trỏ p.
*/
// b) Hãy cho biết kết quả in ra chương trình khi chạy.
// Giải thích rõ ràng tại sao có kết quả như vậy

/*
Khi chạy chương trình, đầu tiên tại dòng L1 chúng ta tạo đối tượng x của lớp ComplexNum với giá trị phần thực là 1 và phần ảo là 9, đối tượng này sẽ được lưu trữ trên stack. Tiếp theo, tại dòng L2, chúng ta tạo đối tượng y của lớp ComplexNum với giá trị phần thực là 5 và phần ảo mặc định là 0, đối tượng này cũng sẽ được lưu trữ trên stack.

Tại dòng L3, chúng ta khai báo con trỏ p kiểu ComplexNum, và tại dòng L4, chúng ta cấp phát động một đối tượng mới của lớp ComplexNum với giá trị phần thực là 11 và phần ảo là 13. Đối tượng này được lưu trữ trên heap, và địa chỉ của nó được gán cho con trỏ p.

Tại dòng L5, chúng ta giải phóng bộ nhớ đã được cấp phát cho đối tượng trên heap được chỉ bằng con trỏ p sử dụng toán tử delete.

Tại dòng L6, chúng ta gán địa chỉ của đối tượng x cho con trỏ p.

Khi hàm main kết thúc, các đối tượng trên stack được giải phóng theo thứ tự ngược với thứ tự được khai báo và tạo ra. Do đó, kết quả được in ra theo thứ tự:

Đối tượng được cấp phát động tại dòng L4 với giá trị phần thực là 11 và phần ảo là 13.
Đối tượng y được tạo tại dòng L2 với giá trị phần thực là 5 và phần ảo là 0.
Đối tượng x được tạo tại dòng L1 với giá trị phần thực là 1 và phần ảo là 9.
*/