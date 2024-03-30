#include <iostream>
#include <fstream>
#include <cmath>

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

    if(sqrt(n) == (ll)sqrt(n)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    return 0;
}