#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "LIGHT"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MAX = 1e5;

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

    ll n, m;
    std::cin >> n >> m;

    std::vector<ll> light_pos(MAX, 0);

    for(ll i = 0; i < n; i++) {
        ll t;
        std::cin >> t;
        light_pos[i] = t--;
    }

    std::vector<ll> light_freq(MAX, 0);

    for(ll i = 0; i < n; i++) {
        ll range, pos = light_pos[i];
        std::cin >> range;
        
        if(pos - range < 0) {
            for(ll j = 0; j <= pos + range; j++) {
                light_freq[j] += 1;
            }
        }
        else {
            for(ll j = pos - range; j <= pos + range; j++) {
                light_freq[j] += 1;
            }
        }
    }

    while(m--) {
        ll t;
        std::cin >> t;
        std::cout << light_freq[t] << " ";
    }

    return 0;
}