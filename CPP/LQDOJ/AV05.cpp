#include <iostream>
#include <fstream>
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

    ll N;
    std::cin >> N;

    bool soduong = false;
    std::vector<ll> A;
    while(N--) {
        ll t;
        std::cin >> t;
        A.push_back(t);
        if(t > 0) {
            soduong = true;
        }
    }

    if(!soduong) {
        std::cout << "-1 -1";
    }
    else {
        for(ll i = 0; i < A.size(); ++i) {
            if(A[i] > 0) {
                std::cout << i + 1 << " ";
                break;
            }
        }
        for(ll i = A.size() - 1; i >= 0; --i) {
            if(A[i] > 0) {
                std::cout << i + 1;
                break;
            }
        }
    }

    return 0;
}