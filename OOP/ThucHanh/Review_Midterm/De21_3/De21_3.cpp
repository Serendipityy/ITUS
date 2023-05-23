//#include<iostream>
//using namespace std;
//static int DesCnt = 0;
//class ObjTest {
//protected:
//	int Val;
//public:
//	ObjTest() { Val = -1; }
//	virtual ~ObjTest() {
//		DesCnt += 2;
//	}
//};
//
//class ChildObj :public ObjTest {
//public:
//	ChildObj(int pVal = 0) {
//		Val = pVal;
//	}
//	~ChildObj() {
//		DesCnt += 3;
//	}
//};
//
//int main() {
//	int n = 8;
//	ObjTest* obj = new ChildObj[n]; // Lệnh (N1)
//	delete[] obj; // Lệnh (D1)
//	obj = new ChildObj(n); // Lệnh (N2)
//	delete obj;
//	cout << "DesCnt=" << DesCnt << endl;
//	return 0;
//}

//a) So sánh điểm khác nhau giữa 2 lệnh new gắn nhãn(N1) và gắn nhãn(N2)

/* - Lệnh(N1) khởi tạo một mảng đối tượng ChildObj với kích thước n, mỗi phần tử 
trong mảng được khởi tạo bởi hàm khởi tạo mặc định của lớp ChildObj.
- Lệnh(N2) khởi tạo một đối tượng ChildObj với giá trị đầu vào pVal = n, 
sử dụng hàm khởi tạo có tham số của lớp ChildObj.
*/


//điểm khác nhau giữa lệnh delete gắn nhãn(D1) và gắn nhãn(D2)

/*
- Lệnh (D1) giải phóng một mảng đối tượng, được cấp phát bởi lệnh new[].
- Lệnh (D2) giải phóng một đối tượng được cấp phát bởi lệnh new.
*/

//
//b) Hãy cho biết kết quả in ra chương trình khi chạy.
//Giải thích rõ ràng tại sao có kết quả như vậy

/*
Trong chương trình, ta định nghĩa hai lớp: lớp ObjTest và lớp ChildObj, trong đó lớp ChildObj là lớp con của lớp ObjTest.

Trong hàm main, ta khởi tạo một mảng gồm n đối tượng ChildObj bằng cách sử dụng toán tử new như sau:
ObjTest* obj = new ChildObj[n];
Mỗi đối tượng ChildObj được khởi tạo sẽ gọi đến hàm khởi tạo của lớp cha ObjTest trước, đặt giá trị của biến protected Val là -1, sau đó gọi đến hàm khởi tạo của lớp con ChildObj với đối số truyền vào là 0 (mặc định nếu không có đối số).

Sau khi khởi tạo mảng các đối tượng ChildObj, biến DesCnt được tăng thêm 2 * n đơn vị, vì mỗi đối tượng ChildObj khi bị hủy sẽ gọi đến hàm hủy của lớp cha ObjTest trước đó, tăng biến DesCnt lên 2 đơn vị.

Sau đó, ta giải phóng vùng nhớ được cấp phát cho mảng các đối tượng ChildObj bằng toán tử delete[] như sau:
delete[] obj;

Sau khi giải phóng vùng nhớ, biến DesCnt được tăng thêm 3 * n đơn vị, vì mỗi đối tượng ChildObj khi bị hủy sẽ gọi đến hàm hủy của lớp con ChildObj trước đó, tăng biến DesCnt lên 3 đơn vị.

Tiếp theo, ta khởi tạo một đối tượng ChildObj mới với đối số truyền vào là n:
obj = new ChildObj(n);
Đối tượng ChildObj này được khởi tạo với giá trị của biến protected Val là n, và sau khi đối tượng này bị giải phóng bằng toán tử delete, biến DesCnt được tăng thêm 5 đơn vị, do khi đối tượng ChildObj bị hủy, nó sẽ gọi đến hàm hủy của lớp con ChildObj trước đó, tăng biến DesCnt lên 3 đơn vị, sau đó sẽ gọi đến hàm hủy của lớp cha ObjTest, tăng biến DesCnt lên thêm 2 đơn vị.

Tổng cộng, biến DesCnt sẽ tăng lên 2 * n + 3 * n + 5 = 45
*/