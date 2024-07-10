#include <bits/stdc++.h>
using namespace std;

#define NAME "DNT"

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

bool isPrime(int n) {
	if(n == 2 || n == 3)
		return true;
	else if(n < 2 || n % 2 == 0 || n % 3 == 0)
		return false;
	else {
		for(int i = 5; i * i <= n; i += 6)
			if(n % i == 0)
				return false;
	}
	return true;
}

int main() {
	fastio();
	docfile();

	
}
