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

    int T;
    std::cin >> T;

    while(T--) {
        ll n;
        std::cin >> n;

        if(n % 2 == 0 && n >= 6) {
            std::cout << 1 << "\n";
        }
        else {
            std::cout << 0 << "\n";
        }
    }

    return 0;
}