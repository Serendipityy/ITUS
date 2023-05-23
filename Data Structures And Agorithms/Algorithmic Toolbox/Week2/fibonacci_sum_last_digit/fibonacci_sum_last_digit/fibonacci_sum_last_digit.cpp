#include <iostream>
using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int fibonacci_sum_efficient(long long n) {
    if (n <= 1) return n;
    long long prev = 0;
    long long curr = 1;
    long long res_sum = 1, seq_sum = 1;
    long long tmp_prev = 0;
    for (long long i = 0; i < 59; i++) {
        tmp_prev = prev;
        prev = curr;
        curr = tmp_prev + curr;
        seq_sum = (seq_sum + curr) % 10;
        if (i < (n - 1) % 60) {
            res_sum = (res_sum + curr) % 10;
        }
    }
    return (seq_sum * (n / 60) % 10 + res_sum) % 10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    cout << fibonacci_sum_efficient(n);
}
