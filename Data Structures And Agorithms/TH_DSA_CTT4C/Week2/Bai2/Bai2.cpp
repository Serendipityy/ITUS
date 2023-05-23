#include<iostream>
#include<time.h>
using namespace std;

//Bai 2: F0 = 1, F1 = 2, F2 = 5;
//F(n + 2) = Fn + F(n - 1).F(n + 1) nếu n >= 1.

//a)
//Ta co: 
//F3 = F(1+2) = F(1) + F(1-1).F(1+1) = F1 + F0.F2 = 2 + 1.5 = 7
//Tuong tu: 
//F4 = F(2 + 2) = F2 + F1.F3 = 5 + 2.7 = 19
//F5 = F(3 + 2) = F3 + F2.F4 = 7 + 5.19 = 102
//Vay: 
//F6 = F(4+2) = F4 + F3.F5 = 19 + 7.102 = 733

//b)
// Dung de quy: 
int Fn_Recursion(int n) {
    if (n == 0 || n == 1) return n + 1;
    if (n == 2) return n + 3;
    return Fn_Recursion(n - 2) + Fn_Recursion(n - 3) * Fn_Recursion(n - 1);
}
// Dung vong lap: 
int Fn_Loop(int n)
{
    int fn = 1, fn1 = 2, fn2 = 5, fn3 = 0;
    for (int i = 3; i <= n; i++)
    {
        fn3 = fn1 + fn * fn2;
        fn = fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;
}
// Dung quy hoach dong: 
int Fn_dp(int n) {
    int f[31]={0};
    f[0] = 1, f[1] = 2, f[2] = 5;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 3] * f[i - 1];
    }
    return f[n];
}
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
    clock_t start, end;
    double time_use;
    start = clock();
	cout << "Fn (dung de quy) = " << Fn_Recursion(n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThoi gian chay de quy: " << time_use;

    start = clock();
    cout << "\nFn (dung vong lap) = " << Fn_dp(n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThoi gian chay vong lap: " << time_use;

    start = clock();
    cout << "\nFn (dung quy hoach dong) = " << Fn_Loop(n);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nThoi gian chay quy hoach dong: " << time_use;
	return 0;
}