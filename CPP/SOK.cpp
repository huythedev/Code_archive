#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>

#define NAME "SOK"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    docfile();

    ll N, K;
    std::cin >> N >> K;

    std::set<ll> vec;
    for (ll i = 0; i < N; i++) {
        ll t;
        std::cin >> t;
        vec.insert(t);
    }

    auto it = vec.end();
    std::advance(it, -K);  
    std::cout << *it;     

    return 0;
}
