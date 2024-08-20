#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "NTO1"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

ll GCD(ll a, ll b) {
    while(b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll N;
    std::cin >> N;

    ll tmp;
    std::cin >> tmp;

    ll t;
    while(std::cin >> t) {
        if(GCD(tmp, t) > 1) {
            std::cout << "NO";
        }
        else {
            std::cout << "YES";
        }
        std::cout << ln;
    }

    return 0;
}