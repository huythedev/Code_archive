#include <bits/stdc++.h>
using namespace std;

#define NAME "tknp02"
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

	int n, k; cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	while (k--) {
		int x; cin >> x;

		auto pos = lower_bound(a.begin(), a.end(), x) - a.begin();



		if (pos == 0)
			cout << 0 << ln;
		else
			cout << pos << ln;
	}

	return 0;
}