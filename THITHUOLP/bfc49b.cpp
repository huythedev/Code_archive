#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
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

    ll n, k;
    std::cin >> n >> k;

    std::vector<ll> a(n);
    for(ll i = 0; i < n; ++i) 
        std::cin >> a[i];

    ll t, tmp = 0;
    while(std::cin >> t) {
        t--;
        a[t]--;
        tmp++;
    }

    for(ll i : a) {
        std::cout << i + tmp << " ";
    }

    return 0;
}