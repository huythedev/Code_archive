#include <iostream>
#include <fstream>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

ll souoc(ll n) {
    ll res = 0;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res++;
            if(i * i != n) {
                res++;
            }
        }
    }
    return res;
}

ll tonguoc(ll n) {
    ll res = 0;
    for(ll i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res += i;
            if(i * i != n) {
                res += n / i;
            }
        }
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll N;
    std::cin >> N;

    std::cout << souoc(N) << " " << tonguoc(N);
    return 0;
}