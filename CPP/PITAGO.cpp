#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "PITAGO"
#define ln '\n'

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

    ld a, b, c;
    std::cin >> a >> b >> c;

    if(a + b > c && a + c > b && b + c > a && a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    return 0;
}