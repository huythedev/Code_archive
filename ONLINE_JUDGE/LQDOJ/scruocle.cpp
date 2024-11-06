#include <bits/stdc++.h>
using namespace std;

#define NAME "scruocle"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

ll odddiv(ll n) {
	ll res = 0;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i % 2 != 0)
				++res;
			if (i != n / i)
				if ((n / i) % 2 != 0)
					++res;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll n; cin >> n;

	cout << odddiv(n);

	return 0;
}