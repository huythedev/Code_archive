#include <iostream>

void docfile() {
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
}

int main() {
    docfile();
    int n, m, k;
    char c1, c2;

    std::cin >> n >> c1 >> m >> c2 >> k;

    if(c1 == 'R') {
        if(k - n < 0) {
            std::cout << k;
        }
        else {
            std::cout << n;
        }
    }
    else {
        k -= n;
        if(k <= 0) {
            std::cout << 0;
        }
        else {
            if(k - m < 0) {
                std::cout << k;
            }
            else {
                std::cout << m;
            }
        }
    }

    return 0;
}