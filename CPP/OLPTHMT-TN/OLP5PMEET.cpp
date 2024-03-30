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

    ld x1, x2, v1, v2;
    std::cin >> x1 >> x2 >> v1 >> v2;

    if(v1 == v2) {
        std::cout << -1;
        return 0;
    }
    else {
        if(x2 > x1 && v2 > v1 || x1 > x2 && v1 > v2 || x1 == x2 && v1 != v2 || x1 != x2 && v1 == v2) {
            std::cout << -1;
            return 0;
        }
        else if(x1 == x2 && v1 == v2) {
            std::cout << 0;
            return 0;
        }
        else {
            ld t = (x2 - x1) / (v1 - v2);
            if(t < 0) {
                std::cout << -1;
                return 0;
            }
            else {
                std::cout << std::fixed << std::setprecision(4) << t;
                return 0;
            }
        }
    }

    return 0;
}