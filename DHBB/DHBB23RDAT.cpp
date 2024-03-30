#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <iomanip>

#define NAME "NAME"
#define ln '\n'

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

    ll n, q;
    std::cin >> n >> q;

    std::vector<ll> t;
    for(ll i = 0; i < n; i++) {
        ll x;
        std::cin >> x;
        t.push_back(x);
    }

    while (q--) {
        ll L, R;
        std::cin >> L >> R;
        --L; --R;
        std::vector<ll> subvec(t.begin() + L, t.begin() + R + 1);

        auto max1_it = std::max_element(subvec.begin(), subvec.end());
        ll pos1 = std::distance(subvec.begin(), max1_it);
        ll max1 = *max1_it;
        subvec.erase(max1_it);

        ll max2 = *std::max_element(subvec.begin(), subvec.end());

        std::cout << max1 + max2 << ln;
    }

    return 0;
}