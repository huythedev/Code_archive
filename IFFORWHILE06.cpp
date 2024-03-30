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

    ld a, b, c;
    std::cin >> a >> b >> c;

    ld tbm = (a * 2 + b * 2 + c) / 5.0;

    if(tbm >= 8) {
        std::cout << "gioi";
    }
    else if(tbm >= 6.5) {
        std::cout << "kha banh";
    }
    else if(tbm >= 5) {
        std::cout << "trung binh";
    }
    else {
        std::cout << "yeu";
    }

    return 0;
}