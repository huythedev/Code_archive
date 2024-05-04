#include <bits/stdc++.h>
using namespace std;

#define NAME "np003"
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

	int T; cin >> T;
	while (T--) {
		ll N;
		cin >> N;

		ld tmp = cbrt(N);
		if ((ll)(tmp + 0.5) * (ll)(tmp + 0.5) * (ll)(tmp + 0.5) == N)
			cout << "YES" << ln;
		else
			cout << "NO" << ln;
	}

	return 0;
}