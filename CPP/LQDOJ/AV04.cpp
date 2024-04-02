#include <iostream>
#include <fstream>
#include <iomanip>
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

    int n;
    std::cin >> n;

    ll t, sum = 0;
    std::vector<ll> A;
    bool soam = false;
    while(std::cin >> t) {
        if(t < 0) {
            soam = true;
            sum += t;
            A.push_back(t);
        }
    }

    if(!soam) {
        std::cout << -1;
        return 0;
    }
    
    std::cout << std::fixed << std::setprecision(2) << (ld)sum / A.size();

    return 0;
}