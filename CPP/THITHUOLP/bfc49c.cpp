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
    if (std::ifstream(NAME ".inp")) {
        std::freopen(NAME ".inp", "r", stdin);
        std::freopen(NAME ".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    docfile();

    std::map<ll, ll> freq;

    ll N;
    std::cin >> N;

    ll t;
    while (std::cin >> t) {
        freq[t]++;
    }

    ll res = 0;

    for (auto& kv : freq) {
        ll count = kv.second;

        if (count == 1 && kv.first % 3 != 0 && kv.first % 2 != 0 && kv.first % 3 != 2) {
            std::cout << -1;
            return 0;
        } else {
            if (count > 1) {
                res += count / 3;
                ll tmp = count % 3;

                if (tmp == 1) {
                    std::cout << -1;
                    return 0;
                } else if (tmp == 2) {
                    res++;
                }
            }
        }
    }

    std::cout << res;

    return 0;
}
