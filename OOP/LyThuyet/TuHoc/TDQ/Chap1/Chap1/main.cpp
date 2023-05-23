#include "Chap1.h"
int main() {
	/*Cat kitty("Kitty", 3, 0.2);
	Cat doraemon("Doraemon", 50, 1.2);*/
	Cat mimi("Mimi", 40, 1.1);
	
	cout << mimi.getName()<<" " 
		<< mimi.getWeight() << " kg " 
		<< mimi.getHeight() << " m"
		<< endl;

	// Tạo số ngẫu nhiên
	srand(time(0)); // seed random (khi đặt bên ngoài nó chỉ lấy con số này 1 lần)
	// và lấy những con số random tiếp theo làm hạt giống tiếp theo
	int left = 5; 
	int right = 18;

	// Tạo 100 số ngẫu nhiên trong đoạn [5, 18]
	for (int i = 0; i < 100; i++) {
		//cout << rand() % 100 << " "; // [0 - 99] [0, 100)

		cout << rand() % (right - left + 1) + left << " "; 
	}
	return 0;
}