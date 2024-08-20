#include <iostream>
#include <fstream>
#include <vector>

#define NAME "divcnt"

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

    int n, q;
    std::cin >> n >> q;

    std::vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    while(q--) {
        int l, r, m;
        std::cin >> l >> r >> m;

        ll res = 0;
        for(int i = l - 1; i < r; ++i) {
            if(m % a[i] == 0) {
                ++res;
            }
        }

        std::cout << res << "\n";
    }

    return 0;
}