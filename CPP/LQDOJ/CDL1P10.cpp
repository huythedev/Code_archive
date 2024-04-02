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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll N;
    std::cin >> N;

    if(N % 2 == 0) {
        std::cout << (N + 1) * N / 2;
    }
    else {
        std::cout << (N + 1) * (N / 2) + (N / 2 + 1);
    }

    return 0;
}