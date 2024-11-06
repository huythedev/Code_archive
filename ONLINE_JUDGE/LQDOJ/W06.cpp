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

    ll n, m;
    std::cin >> n >> m;

    for(ll i = 1; i <= min(n, m); ++i) {
        if(n % i == 0 && m % i == 0) {
            std::cout << i << " ";
        }
    }

    return 0;
}