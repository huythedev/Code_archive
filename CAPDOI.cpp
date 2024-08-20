#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <unordered_map>

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

ll countSimilarPairs(std::vector<ll> arr, ll n,ll x) {
    std::unordered_map<ll, ll> hash_table;
    int cnt = 0;

    for (ll i = 0; i < n; ++i) {
        ll complement = x - arr[i];
        if (hash_table.find(complement) != hash_table.end()) {
            cnt += hash_table[complement];
        }
        hash_table[arr[i]]++;
    }

    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll n, x;
    std::cin >> n >> x;

    std::vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    ll res = countSimilarPairs(arr, n, x);
    std::cout << res;

    return 0;
}