#include <iostream>
#include <fstream>
#include <string>

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

    string n;
    int MAX = INT_MIN;

    getline(std::cin, n);
    for(char c : n) {
        MAX = max(c - '0', MAX);
    }
    std::cout << MAX;

    return 0;
}