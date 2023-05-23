#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_efficient(long long n, long long m) {
    if (n <= 1) return n;
    long long prev = 0;
    long long curr = 1;
    long long tmp_prev = 0;
    vector<long> pisano;
    pisano.push_back(0);
    pisano.push_back(1);
    while (true) {
        tmp_prev = prev;
        prev = curr;
        curr = (tmp_prev + curr) % m;
        if (curr == 1 && prev == 0) break;
        else pisano.push_back(curr);
    }
    pisano.pop_back();
    long index = n % pisano.size();
    return pisano.at(index);
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_efficient(n, m) << "\n";
}
