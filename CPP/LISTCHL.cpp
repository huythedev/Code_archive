#include <iostream>
#include <fstream>

#define NAME "LISTCHL"
#define ln '\n'

typedef long long ll;

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

    ll n, k;
    std::cin >> n >> k;

    ll current[k];
    
    for (ll i = 0; i < k; ++i) {
        current[i] = 1;  
    }

    while (true) {
        for (ll i = 0; i < k; ++i) {
            std::cout << current[i] << " ";
        }
        std::cout << ln;

        ll j = k - 1;
        while (j >= 0 && current[j] == n) {
            --j;
        }

        if (j < 0) {
            break;
        }

        ++current[j];
        for (ll l = j + 1; l < k; ++l) {
            current[l] = 1;
        }
    }

    return 0;
}
