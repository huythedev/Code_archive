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

    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = i; j < i + i; ++j) {
            std::cout << j << " ";
        }
        std::cout << " \n";
    }

    return 0;
}