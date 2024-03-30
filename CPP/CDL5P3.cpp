#include <iostream>
#include <fstream>
#include <string>

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

    std::string Ho, dem, ten;
    std::cin >> Ho >> dem >> ten;

    std::cout << Ho << " " << dem << " " << ten;

    return 0;
}