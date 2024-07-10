#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define NAME "DIFF"

void docfile() {
	if (ifstream(NAME ".inp")) {
		freopen(NAME ".inp", "r", stdin);
		freopen(NAME ".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	docfile();

	int L, R;
	cin >> L >> R;

	ll mindiff = LLONG_MAX;
	int res = L;
	for(int M = L; M <= R; ++M) {
		ll sum_L = (ll)(M + L) * (M - L + 1) / 2;
		ll sum_R = (ll)(R + M + 1) * (R - (M + 1) + 1) / 2;

		//cout << sum_L << ' ' << sum_R << endl;

		if(mindiff > abs(sum_L - sum_R)) {
			mindiff = abs(sum_L - sum_R);
			res = M;
		}
	}

	cout << res;
	return 0;
}

