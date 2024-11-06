#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1619"
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

	vector<pair<int, int>> a;
	for (int i = 0; i < n; ++i) {
		int u, v; cin >> u >> v;

		a.push_back({u, 1});
		a.push_back({v, -1});
	}

	sort(a.begin(), a.end());

	int t = 0, res = 0;

	for (int i = 0; i < (int)a.size(); i++) {
		int m = a[i].second;
		t += m;
		res = max(res, t);
	}

	cout << res;

	return 0;
}