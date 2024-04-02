#include <iostream>
#include <fstream>
#include <vector>

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

    ll freq[1000005] = {0};

    ll n;
    std::cin >> n;

    std::vector<ll> A;
    for(ll i = 0; i < n; ++i) {
        ll t;
        std::cin >> t;
        A.push_back(t);
        freq[t]++;
    }

    for(ll n : A) {
        std::cout << n << " " << freq[n] << "\n";
    }
    return 0;
}
