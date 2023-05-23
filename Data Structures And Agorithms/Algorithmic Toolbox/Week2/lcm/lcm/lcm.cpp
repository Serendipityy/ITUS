#include <iostream>
using namespace std;
long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b,a%b);
}
long long lcm_efficient(int a, int b) {
    int g = gcd(a, b);
    return(a * b) / g;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    //std::cout << lcm_naive(a, b) << std::endl;
    cout << lcm_efficient(a, b) << endl;
    return 0;
}
