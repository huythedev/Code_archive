#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

#define NAME "NAME"

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

    ll n;
    std::cin >> n;

    std::vector<ll> vec;
    while(n--) {
        ll t;
        std::cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end());

    ll freq[1000005] = {0};

    std::set<ll> tmp;
    for(ll n : vec) {
        tmp.insert(n);
        freq[n]++;
    }

    for(auto it : tmp) {
        std::cout << it << " " << freq[it] << "\n";
    }

    return 0;
}
