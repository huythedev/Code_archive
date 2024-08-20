#include <iostream>
#include <fstream>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

const ll MOD = 2147483648;

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

    ll N;
    std::cin >> N;

    ll res = 0;
    while(N--) {
        ll t;
        std::cin >> t;
        res = (res + t) % MOD;
    }

    std::cout << res;

    return 0;
}

