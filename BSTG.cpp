#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "BSTG"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

bool isTG(ll a, ll b, ll c) {
	if(a + b > c && a + c > b && b + c > a) 	
		return true;
	return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

	ll n;
	std::cin >> n;
	
	std::vector<ll> vec(n);
	ll t;
	for(ll i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}
	
	ll res = 0;
	for(ll i = 0; i < n - 2; ++i) {
		for(ll j = i + 1; j < n - 1; ++j) {
			for(ll k = j + 1; k < n; ++k) {
				if(isTG(vec[i], vec[j], vec[k])) {
					++res;
				}
			}
		}
	}
	
	std::cout << res;

    return 0;
}