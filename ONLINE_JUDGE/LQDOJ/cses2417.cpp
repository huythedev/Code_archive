#include <bits/stdc++.h>
using namespace std;

#define NAME "cses2417"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const ll MAXN = 1e6 + 6;
ll spf[MAXN];

void sieve() {
	spf[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		spf[i] = i;

	for (ll i = 2; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (ll j = i * i; j < MAXN; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

ll cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	sieve();

	ll n; cin >> n;
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		vector<ll> v;
		while (x > 1) {
			ll y = spf[x];
			v.push_back(y);
			while (x % y == 0)
				x /= y;
		}
		ll k = v.size();
		for (ll s = 1; s < (1 << k); s++) {
			ll p = 1;
			for (ll j = 0; j < k; j++) {
				if (s >> j & 1)
					p *= v[j];
			}
			ll sgn = -1;
			if (__builtin_popcount(s) & 1)
				sgn = 1;

			res += sgn * cnt[p];
			cnt[p]++;
		}
	}
	cout << n * (n - 1) / 2 - res;

	return 0;
}