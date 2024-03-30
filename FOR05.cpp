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

ll tonguoc(ll n){
    ll tong = 0;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            tong += i; 
            if(i != n / i){
                tong += n / i; 
            }
        }
    }
    return tong;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll n;
    std::cin >> n;

    if(tonguoc(n) == 2 * n){
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }

    return 0;
}
