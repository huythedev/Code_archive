#include <iostream>
#include <fstream>
#include <cmath>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

ll demuoc(ll n){
    ll dem = 0; // n 
    for(ll i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
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

    ll n;
    std::cin >> n;

    std::cout << demuoc(n);

    return 0;
}