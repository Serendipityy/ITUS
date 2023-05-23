//#include<iostream>
//using namespace std;
//class Base {
//public:
//	Base() {};
//	virtual ~Base() { cout << "it's destructor of Base class!"; };
//	virtual void mfunc() { cout << "it's mfunc of Base class!\n"; };
//};
//class Drived_1 :public Base {
//public:
//	Drived_1() {};
//	~Drived_1() { cout << "it's destructor of Drived_1 class!"; };
//	// Override member function mfunc()
//	virtual void mfunc() { cout << "it's mfunc of Drived_1 class!\n"; };
//};
//class Drived_2 : public Base {
//public:
//	Drived_2() {};
//	~Drived_2() { cout << "it's destructor of Drived_2 class!"; };
//	// Override member function mfunc()
//	virtual void mfunc() { cout << "it's mfunc of Drived_2 class!\n"; };
//};
//int main() {
//	Base b; //(1)
//	Base* pb = new Base(); //(2)
//	Drived_1 D1; //(3)
//	Drived_2 D2; //(4)
//	Drived_1* pD1 = new Drived_1(); //(5)
//	Base* pbD1 = new Drived_1(); //(6)
//	Base** roster = new Base * [3]; //(7)
//	for (int i = 0; i < 3; i++) { //(8)
//		roster[i] = NULL; //(9)
//	}
//	roster[0] = new Drived_1(); //(10)
//	roster[1] = new Drived_2(); //(11)
//	roster[2] = new Drived_1(); //(12)
//	for (int i = 0; i < 3; i++) {
//		Drived_1* ptr = dynamic_cast<Drived_1*>(roster[i]);
//		if(ptr!=NULL) {
//			ptr->mfunc();
//		}
//	}
//	return 0;
//}

//a) Giải thích ngắn gọn các lệnh từ (1),...,(12) làm gì?
/*
(1) Tạo đối tượng Base b thông qua constructor mặc định.
(2) Cấp phát động bộ nhớ cho con trỏ pb kiểu Base, trỏ đến đối tượng Base được khởi tạo thông qua constructor mặc định.
(3) Tạo đối tượng Drived_1 D1 thông qua constructor mặc định.
(4) Tạo đối tượng Drived_2 D2 thông qua constructor mặc định.
(5) Cấp phát động bộ nhớ cho con trỏ pD1 kiểu Drived_1, trỏ đến đối tượng Drived_1 được khởi tạo thông qua constructor mặc định.
(6) Cấp phát động bộ nhớ cho con trỏ pbD1 kiểu Base, trỏ đến đối tượng Drived_1 được khởi tạo thông qua constructor mặc định. Ta có kiểu dữ liệu khác nhau của con trỏ và đối tượng trỏ đến, đây là một ví dụ về đa hình.
(7) Cấp phát động bộ nhớ cho mảng con trỏ roster kiểu Base*, có 3 phần tử.
(8) Vòng lặp for chạy từ i = 0 đến i = 2.
(9) Gán giá trị NULL cho phần tử thứ i của mảng con trỏ roster.
(10) Cấp phát động bộ nhớ cho phần tử thứ 0 của mảng con trỏ roster kiểu Drived_1.
(11) Cấp phát động bộ nhớ cho phần tử thứ 1 của mảng con trỏ roster kiểu Drived_2.
(12) Cấp phát động bộ nhớ cho phần tử thứ 2 của mảng con trỏ roster kiểu Drived_1.
*/
//b) Cho biết kết quả chạy chương trình, giải thích rõ ràng tại sao có kết quả đó

/*
* Kết quả:
it's mfunc of Drived_1 class!

it's mfunc of Drived_1 class!

it's destructor of Drived_2 class!
it's destructor of Base class!
it's destructor of Drived_1 class!
it's destructor of Base class!
it's destructor of Base class!

------------------------------------------
* Giải thích: 
Đầu tiên, chương trình tạo ra một số đối tượng và con trỏ đến các lớp 
Base, Drived_1 và Drived_2, sau đó tạo ra một mảng các con trỏ đến các lớp Base (biến roster).

Các đối tượng và con trỏ được tạo trong chương trình:

Tạo đối tượng b từ lớp Base.
Tạo đối tượng thông qua con trỏ pb đến lớp Base.
Tạo đối tượng D1 từ lớp Drived_1.
Tạo đối tượng D2 từ lớp Drived_2.
Tạo đối tượng thông qua con trỏ pD1 đến lớp Drived_1.
Tạo đối tượng thông qua con trỏ pbD1 đến lớp Drived_1.
Tạo một mảng các con trỏ Base với độ dài 3 (biến roster).
Khởi tạo giá trị của mảng roster.
Gán giá trị NULL cho các phần tử trong mảng roster.
Gán giá trị con trỏ trỏ đến đối tượng Drived_1 mới được tạo (thông qua con trỏ roster[0]).
Gán giá trị con trỏ trỏ đến đối tượng Drived_2 mới được tạo (thông qua con trỏ roster[1]).
Gán giá trị con trỏ trỏ đến đối tượng Drived_1 mới được tạo (thông qua con trỏ roster[2]).

Sau đó, vòng lặp for duyệt qua các phần tử của mảng roster và kiểm tra xem đối tượng đó 
có phải là một đối tượng của lớp Drived_1 hay không thông qua dynamic_cast. 
Nếu đúng, phương thức mfunc của lớp Drived_1 được gọi.

Kết quả là các phần tử ở vị trí 0 và 2 trong mảng roster đều là các đối tượng của lớp Drived_1, 
do đó phương thức mfunc của lớp Drived_1 được gọi cho cả hai đối tượng đó.

Sau khi hoàn thành vòng lặp for và thực hiện xong phần code của hàm main(), 
các đối tượng được giải phóng theo thứ tự đảo ngược với thứ tự tạo ra chúng. 
Đầu tiên, đối tượng con trỏ thứ ba được giải phóng (có kiểu Drived_1), sau đó đối tượng con trỏ 
thứ hai (có kiểu Drived_2), và cuối cùng đối tượng con trỏ thứ nhất (có kiểu Drived_1). 
Khi giải phóng đối tượng con trỏ thứ ba, trước tiên destructor của lớp Drived_1 được gọi, 
sau đó đến destructor của lớp Base. Tương tự, khi giải phóng đối tượng con trỏ thứ hai, destructor
của lớp Drived_2 được gọi, và sau đó đến destructor của lớp Base. Khi giải phóng đối tượng con trỏ thứ nhất,
destructor của lớp Drived_1 được gọi, sau đó đến destructor của lớp Base.


-----------------------------------------
*/