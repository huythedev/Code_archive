#include <iostream>
#include <fstream>
#include <vector>

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

    ll N;
    std::cin >> N;

    std::vector<ll> A;
    bool soam = false;
    for(ll i = 0; i < N; ++i) {
        ll t;
        std::cin >> t;
        A.push_back(t);
        if(t < 0) {
            soam = true;
        }
    }

    if(!soam) {
        std::cout << -1 << " " << -1;
    }
    else {
        for(ll i = 0; i < N; ++i) {
            if(A[i] < 0) {
                std::cout << i + 1 << " ";
                break;
            }
        }
        for(ll i = N - 1; i >= 0; --i) {
            if(A[i] < 0) {
                std::cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}