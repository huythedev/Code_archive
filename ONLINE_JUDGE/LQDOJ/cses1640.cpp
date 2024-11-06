#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1640"
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

	int n, x; cin >> n >> x;

	map<int, int> mp;
	for (int i = 1, a; i <= n; ++i) {
		cin >> a;
		if (mp.count(x - a)) {
			cout << mp[x - a] << " " << i;
			return 0;
		}
		mp[a] = i;
	}
	cout << "IMPOSSIBLE";

	return 0;
}