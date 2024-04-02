#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "NAME"
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

    ll a, b, c;
    std::cin >> a >> b >> c;

    ll res = 0;
    if(a % 2 != 0) {
        res += a / 2 + 1;
    }
    else {
        res += a / 2;
    }

    if(b % 2 != 0) {
        res += b / 2 + 1;
    }
    else {
        res += b / 2;
    }

    if(c % 2 != 0) {
        res += c / 2 + 1;
    }
    else {
        res += c / 2;
    }

    std::cout << "So ban toi thieu can mua: " << res;

    return 0;
}