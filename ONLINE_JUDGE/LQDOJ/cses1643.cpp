#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1643"
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

	int n; cin >> n;
	vector<int> x(n);

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	ll tmp = 0;
	ll res = LLONG_MIN;

	for (int i = 0; i < n; ++i) {
		tmp = max((ll)x[i], tmp + x[i]);
		res = max(res, tmp);
	}

	cout << res;

	return 0;
}