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

    ll n;
    std::cin >> n;

    ll res = 0, i = 1;

    while(i <= n) {
        if(i % 2 != 0) {
            res += i;
        }
        i++;
    }

    std::cout << res;

    return 0;
}