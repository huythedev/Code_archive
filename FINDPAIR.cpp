#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll N, X;
    std::cin >> N >> X;

    std::vector<ll> A(N);
    for(ll i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(ll i = 0; i < N - 1; i++) {
        for(ll j = i + 1; j < N; j++) {
            if(A[i] + A[j] == X) {
                std::cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    std::cout << "No solution";

    return 0;
}