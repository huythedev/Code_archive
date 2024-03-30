#include <iostream>
#include <fstream>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    const int a = 2468, b = 1234;

    std::cout << "2468 + 1234 = " << a + b << "\n";
    std::cout << "2468 - 1234 = " << a - b << "\n";
    std::cout << "2468 * 1234 = " << a * b << "\n";
    std::cout << "2468 // 1234 = " << a / b << "\n";

    return 0;
}