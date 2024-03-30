#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <map>

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
    //docfile();

    ll n, k;
    std::cin >> n >> k;

    std::map<ll, ll> freq;
    ll t;
    while(std::cin >> t) {
        freq[t]++;
    }

    ll sogt = 0, res = 0;
    for(auto& tmp : freq) {
        ll count = tmp.second;
        if(count >= k) {
            sogt++;
            res += tmp.first;
        }
    }

    std::cout << sogt << " " << res;

    return 0;
}