#include <iostream>

int GCD(int a, int b) {
    while(a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main() {
    int x, k;
    std::cin >> x >> k;
    for(int i = x; i <= x + 2 * k; i += 2) {
        if(GCD(x, i) == 1) {
            std::cout << 1;
            return 0;
        }
    }
    std::cout << GCD(x, x + 2 * k);
    return 0;
}