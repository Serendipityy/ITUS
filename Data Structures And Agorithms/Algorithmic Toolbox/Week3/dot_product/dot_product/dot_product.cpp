#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
    // write your code here
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    vector<long long> c;
    c.reserve(a.size());

    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(c),
        std::multiplies<long long>());

    long long result = std::accumulate(c.begin(), c.end(), 0ll);

    return result;
    //long long result = 0;
    //for (size_t i = 0; i < a.size(); i++) {
    //    result += ((long long)a[i]) * b[i];
    //}
    //return result;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::cout << max_dot_product(a, b) << std::endl;
}
