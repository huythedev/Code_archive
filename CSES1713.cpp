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

int demuoc(int n){
    int dem = 0; 
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            dem += 1; 
            if(i != n / i){
                dem += 1; 
            }
        }
    }
    return dem;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    int n;
    std::cin >> n;

    while(n--) {
        int x;
        std::cin >> x;
        std::cout << demuoc(x) << ln;
    }

    return 0;
}