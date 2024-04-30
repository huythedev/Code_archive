#include <bits/stdc++.h>
using namespace std;

#define NAME "24sna3"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll a, b; cin >> a >> b;
	a--; b--;

	vector<ll> lipon(1e5 + 5);
	lipon[0] = 14;
	for (ll i = 1; i < (ll)1e5 + 5; ++i)
		lipon[i] = (lipon[i - 1] * 2 + 2) % 1000;

	ll res = 0;
	for (ll i = a; i <= b; ++i)
		res += lipon[i];

	cout << res;

	return 0;
}