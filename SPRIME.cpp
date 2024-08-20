#include <bits/stdc++.h>
using namespace std;

#define NAME "SPRIME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool isPrime(int n) {
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int sum(int n) {
	int s = 0;
	while(n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int T; cin >> T;
	while(T--) {
		int L, R; cin >> L >> R;
		int res = 0;
		for(int i = L; i <= R; i++) {
			if(isPrime(i)) 
				if(sum(i) % 5 == 0)
					++res;
		}

		cout << res << ln;
	}

	return 0;
}