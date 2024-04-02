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

    ll n, x;
    std::cin >> n >> x;

    ll count = 0;

    ll t;
    while(std::cin >> t) {
        if(t == x) {
            ++count;
        }
    }

    std::cout << count;

    return 0;
}