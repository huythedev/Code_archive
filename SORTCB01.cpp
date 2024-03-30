#include <iostream>
#include <fstream>
#include <vector>
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

    ll n;
    std::cin >> n;

    std::vector<ll> A;
    for(ll i = 0; i < n; ++i) {
        ll x;
        std::cin >> x;
        A.push_back(x);
    }

    sort(A.rbegin(), A.rend());

    for(ll n : A) {
        std::cout << n << " ";
    }

    return 0;
}