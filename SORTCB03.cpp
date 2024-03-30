#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> A;
    for(ll i = 0; i < N; i++) {
        ll t;
        std::cin >> t;
        A.push_back(t);
    }

    sort(A.rbegin(), A.rend());

    std::cout << A[K - 1];

    return 0;
}