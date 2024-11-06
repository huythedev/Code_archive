#include <bits/stdc++.h>
using namespace std;

#define NAME "dx"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int numlength(ll n) {
	int res = 0;
	while (n) {
		res++;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll x; cin >> x;

	int x_sz = numlength(x);

	vector<ll> vec(9);
	for (int i = 0; i < 9; ++i) {
		ll tmp = 0;
		for (int j = 0; j < x_sz; ++j)
			tmp = tmp * 10 + i + 1;

		vec[i] = tmp;
	}

	ll min_y = LLONG_MAX;
	bool tmp = false;
	for (ll i : vec)
		if (i - x > 0) {
			min_y = min(i - x, min_y);
			tmp = true;
		}

	if (tmp)
		cout << min_y;
	else {
		x_sz++;
		for (int i = 0; i < 9; ++i) {
			ll tmp = 0;
			for (int j = 0; j < x_sz; ++j)
				tmp = tmp * 10 + i + 1;

			vec[i] = tmp;
		}

		for (ll i : vec)
			if (i - x > 0)
				min_y = min(i - x, min_y);

		cout << min_y;
	}

	return 0;
}