#include "Chap2.h"

int main() {
	//Point2D a;
	//cout << a.toString() << endl;

	//Point2D b(2, 4);
	//cout << b.toString() << endl;

	//Point2D c(3);
	//cout << c.toString() << endl;

	// Memory leak (xin cấp phát nhưng không thu hồi)	
	// Nếu cấp phát bằng tay => nhớ thu hồi
	// - Quên thì sao?
	// Vấn đề 1: Là con người, chắc chắn Quên
	// Vấn đề 2: Bạn có sở hữu vòng đời biến đó hay không?
	// Java / C#: bộ thu gom rác tự động
	// Con trỏ thông minh
	//Point2D* a = new Point2D();
	//cout << a->toString() << endl;

	//Point2D* b = new Point2D(2, 4);
	//cout << b->toString() << endl;

	//Point2D* c = new Point2D(3);
	//cout << c->toString() << endl;

	//delete a;
	//delete c;
	//delete b;

	// Lí giải tại sao lại thấy một mớ destructor
	// Gợi ý: function call stack, biến cục bộ tự động được cấp phát và thu hồi
	// Đối số của hàm nếu là tham trị thì sẽ được tạo ra bản sao
	// ==> Copy constructor
	Point2D b(2, 4);
	Point2D c(3);

	Line2D line(b, c);
	cout << line.toString() << endl; // ((2,4), (3,3))
	cout << line.length() << endl; // In ra độ dài của đường thẳng


	return 0;
}
