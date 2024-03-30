#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "SPRIME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(ll n) {
	for(ll i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			return false;
		}
	}
	return n > 1;
}

ll tongcs(ll n) {
	ll res = 0; 
	while(n > 0) {
		res += n % 10;
		n /= 10;
	}
	
	return res;
}

bool dacbiet(ll n) {
	if(isPrime(n) && tongcs(n) % 5 == 0) {
		return true;
	}
	return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();
    
    ll Tests;
    std::cin >> Tests;

	while(Tests--) {
		ll L, R;
		std::cin >> L >> R;
		
		ll res = 0;
		for(ll i = L; i <= R; ++i) {
			if(dacbiet(i)) 
				++res;
		}
		
		std::cout << res << ln;
	}

    return 0;
}