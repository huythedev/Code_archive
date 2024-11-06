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

ll GCD(ll a, ll b) {
    while(b) {
        ll r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll n, m;
    std::cin >> n >> m;

    std::cout << GCD(n, m);

    return 0;
}