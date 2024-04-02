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

    ll N;
    std::cin >> N;

    ll res = 0;
    ll t, phantu = 0;
    while(std::cin >> t) {
        if(t > 0) {
            res += t;
            ++phantu;
        }
    }

    std::cout << phantu << " " << res;
    return 0;
}