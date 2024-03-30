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

    std::vector<ll> vec;
    ll n;
    while(std::cin >> n) {
        vec.push_back(n);
    }

    std::sort(vec.rbegin(), vec.rend());
    for(ll n : vec) {
        std::cout << n << " ";
    }

    return 0;
}
