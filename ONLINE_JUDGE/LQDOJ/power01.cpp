#include <bits/stdc++.h>
using namespace std;

#define NAME "power01"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

ll mod, m;
ll f(ll a, ll n, ll mod) {
	ll res = a, ans = 0;
	while (n) {
		if (n % 2)
			ans = (ans + res) % mod;
		res = (res + res) % mod;
		n /= 2;
	}
	return ans;
}

ll po(ll a, ll n) {
	ll res = a, ans = 1;
	while (n) {
		if (n % 2)
			ans = f(ans, res, mod);

		res = f(res, res, mod);
		n /= 2;
	}
	return ans;
}

ll solve(ll p, ll n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return (p + 1) % mod;
	if (n % 2 == 1)
		return (f(p, solve(p, n - 1), mod) + 1) % mod;
	return (f((po(p, n / 2) + 1), ((solve(p, n / 2) - 1 + mod) % mod), mod) + 1) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll x, n, m;
	cin >> x >> n >> m;

	mod = m;
	cout << solve(x, n);
}