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

ll dodep(std::string st) {
    ll dep = 0;
    for(char c : st) {
        if(c - '0' >= 0 && c - '0' <= 9) {
            dep += c - '0';
        }
    }
    return dep;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    std::string n;
    std::cin >> n;

    ll dep = dodep(n);

    while(dep / 10 > 1) {
        dep = dodep(std::to_string(dep));
    }

    std::cout << dep;

    return 0;
}