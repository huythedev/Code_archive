#include <bits/stdc++.h>
using namespace std;

#define NAME "24sna5"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const ll mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll a, b; cin >> a >> b;
	--b;
	ll n = b - a + 1;
	ll first_term = a * (a - 1) * (2 * a - 1) / 6;
	ll last_term = b * (b + 1) * (2 * b + 1) / 6;

	cout << ((2 * a % mod * a % mod * a % mod + 3 * a % mod * a % mod + a % mod) * (b - a + 1) / 6) % mod;
	return 0;
}