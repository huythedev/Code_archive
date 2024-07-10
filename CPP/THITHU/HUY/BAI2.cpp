#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI2"

typedef long long ll;

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

int main() {
	fastio();
	docfile();

	ll a, b; cin >> a >> b;

	ll x = 0;
	while(__gcd(a + x, b + x) != b - a)
		++x;

	cout << x;

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}

