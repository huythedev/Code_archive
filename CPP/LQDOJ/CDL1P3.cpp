#include <iostream>
#include <fstream>
#include <iomanip>

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

    ld kg;
    std::cin >> kg;

    std::cout << std::fixed << std::setprecision(2) << kg * 2.205;

    return 0;
}