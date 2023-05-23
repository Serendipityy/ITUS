#include<iostream>
#include<time.h>
using namespace std;
//Bai 1: Tinh so Fibonacci thu n
//F(n) = F(n - 1) + F(n - 2) với n > 2; F(0) = 0, F(1) = 1

// Su dung de quy
int Fibonacci_recursion(int n) {
	if (n == 0 || n == 1) return n;
	return Fibonacci_recursion(n - 1) + Fibonacci_recursion(n - 2);
}

// Khong su dung de quy
// Vong lap
int Fibonacci_loop(int n) {
	if (n == 0) return 0;
	int x = 0, y = 1;
	for (int i = 2; i <= n; i++) {
		int temp = x + y;
		x = y;
		y = temp;
	}
	return y;
}
// Dynamic programming, bottom up
int t[31] = { 0 };
int Fibonacci_dp(int n) {
	if (n == 0 || n == 1) return n;
	t[0] = 0, t[1] = 1;
	for (int i = 2; i <= n; i++) {
		t[i] = t[i - 1] + t[i - 2];
	}
	return t[n];
}

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	clock_t start, end; // Khai bao bien thoi gian
	double time_use; // Thoi gian su dung
	start = clock(); // Lay thoi gian truoc khi thuc hien thuat toan
	cout << "\nSo Fibonacci thu " << n << " su dung de quy la: " << Fibonacci_recursion(n);
	end = clock(); // Lay thoi gian sau khi thuc hien
	time_use = (double)(end - start) / CLOCKS_PER_SEC; // Tinh thoi gian su dung
	cout << "\nThoi gian chay de quy: " << time_use;

	start = clock();
	cout << "\nSo Fibonacci thu " << n << " su dung vong lap la: " << Fibonacci_loop(n);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nThoi gian chay vong lap: " << time_use;

	start = clock();
	cout << "\nSo Fibonacci thu " << n << " su dung dynamic programming la: " << Fibonacci_dp(n);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nThoi gian chay dynamic programming: " << time_use;
	return 0;
}
