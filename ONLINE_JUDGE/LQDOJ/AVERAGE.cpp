#include <iostream>
#include <fstream>
#include <climits>

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

    ll N;
    std::cin >> N;

    ll res = LLONG_MIN;
    ll t;
    while(std::cin >> t) {
        res = std::max(res, t);
    }

    std::cout << res;

    return 0;
}