#include <iostream>
#include <fstream>
#include <iomanip>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

const ld PI = 3.14;

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

    ld R;
    std::cin >> R;

    std::cout << std::fixed << std::setprecision(1) << PI * R * 2 << "\n" << PI * R * R;

    return 0;
}