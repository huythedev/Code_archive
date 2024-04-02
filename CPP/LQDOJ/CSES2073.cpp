#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
    std::string s;
    std::cin >> s;

    while(m--) {
        ll a, b;
        std::cin >> a >> b;
        a--; b--;
        reverse(s.begin() + a, s.begin() + b + 1);
    }

    std::cout << s;

    return 0;
}