#include <bits/stdc++.h>
using namespace std;

#define NAME "PTKMAX"
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

	ll N; cin >> N;

	ll tmp = sqrt(8 * N + 1);
	tmp = (tmp - 1) / 2;
	for (ll i = tmp; i > 0; --i) {
		ll a = 2 * N - i - i * i, b = 2 * (i + 1);

		if (a % b == 0) {
			if (a == 0)
				cout << i;
			else
				cout << i + 1;

			return 0;
		}
	}

	cout << 0;

	return 0;
}