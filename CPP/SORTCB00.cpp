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

    ll n;
    std::cin >> n;
    
    std::vector<ll> A(n);
    for(ll i = 0; i < n; ++i) {
        ll t;
        std::cin >> t;
        A[i] = t;
    }

    std::sort(A.begin(), A.end());

    for(ll i : A) {
        std::cout << i << " ";
    }

    return 0;
}