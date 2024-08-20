#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>

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

const ll MAX_A = 1e9 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    std::vector<ll> freq;
    freq.reserve(MAX_A);

    ll N;
    std::cin >> N;

    std::vector<ll> a(N);
    std::set<ll> tmp;
    for(ll i = 0; i < N; ++i) {
        std::cin >> a[i];
        tmp.insert(a[i]);
        freq[a[i]]++;
    }

    for(ll n : a) {
        ll res = 0;
        for(ll t : tmp) {
            if(t < n) {
                res += freq[t];
            }
        }

        std::cout << res << " ";
    }

    return 0;
}
