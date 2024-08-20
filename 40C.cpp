#include <iostream>
#include <fstream>

#define NAME "FRAC"

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

    int t;
    std::cin >> t;
    while(t--) {
        ll a, b;
        std::cin >> a >> b;
        if(__gcd(a, b) == 1) {
            std::cout << "Yes\n";
        }
        else {
            std::cout << "No\n";
        }
    }
    return 0;
}