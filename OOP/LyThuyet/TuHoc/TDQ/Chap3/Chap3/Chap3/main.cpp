#include "Chap3.h"
int main() {
	//int x = 10;
	//int y = 7;
	//Swap(x, y);
	//cout << "x = " << x << ", ";
	//cout << "y = " << y << endl;

	//Point x1(2, 2);
	//Point y1(3, 3);
	//Line line(x1, y1);
	//cout << line.toString() << endl;
	//cout << line.length() << endl;


	Point a(2, 3);
	read(&a);

	// Một con trỏ bình thường: có thể trỏ đến vùng nhớ mới,
	// thay đổi dữ liệu bên trong được

	// Nếu thêm từ khóa const ở bên ngoài thì dữ liệu bên trong
	// không thay đổi được
	//const int* p = new int[2];

	// Nếu thêm từ khóa const ở bên trong thì nội dung bên trong
	// vẫn được phép thay đổi nhưng bên ngoài thì không đổi được
	// không được phép trỏ vào vùng trỏ mới
	//int* const p = new int[2];

	//-> const ở bên ngoài thì bên trong không thay đổi
	// const ở bên trong thì không thay đổi bên ngoài
	// vừa trong vừa ngoài thì chỉ được trỏ trong đúng vùng đó

	int*p = new int[2];
	p[0] = 0;
	p[1] = 1;

	p = new int[3];
}
