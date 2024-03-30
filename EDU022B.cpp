#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

#define NAME "NEGPAIRS"

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

    int n;
    std::cin >> n;

    std::vector<ll> a(n);

    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    ll res = 0;
    std::unordered_set<ll> prefix_sums;

    ll current_sum = 0;
    for(int i = 0; i < n; ++i) {
        current_sum += a[i];

        res += prefix_sums.count(current_sum * 2);

        prefix_sums.insert(current_sum);
    }

    std::cout << res;
    return 0;
}
