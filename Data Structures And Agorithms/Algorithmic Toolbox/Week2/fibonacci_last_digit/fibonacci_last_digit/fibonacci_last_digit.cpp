#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit_efficient(int n) {
    if (n <= 1) return n;

    long long previous = 0;
    long long current = 1;
    long long tmp_previous = 0;

    for (int i = 0; i < n - 1; i++) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }

    return current;
}
int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_efficient(n);
    std::cout << c << '\n';
}
