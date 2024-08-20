#include <iostream>
#include <fstream>

#define NAME "DD"

typedef long long ll;

void docfile() {
    if (std::ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    docfile();

    ll A, N;
    std::cin >> A >> N;

    A %= 10;
    ll result = 1;

    for (ll i = 0; i < N; ++i) {
        result = (result * A) % 10;
    }

    std::cout << result;

    return 0;
}
