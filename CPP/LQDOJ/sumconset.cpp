#include <bits/stdc++.h>
using namespace std;

#define NAME "sumconset"
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

	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	int res = 0;
	ll prefixsum = 0;
	int L = 0;

	for (int R = 0; R < n; ++R) {
		prefixsum += a[R];

		while (prefixsum > t) {
			prefixsum -= a[L];
			L++;
		}

		res = max(res, R - L + 1);
	}

	cout << res;

	return 0;
}