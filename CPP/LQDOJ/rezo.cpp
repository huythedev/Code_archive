#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
	ll t[n + 1];
	t[0] = 0;
	map<ll, int> mp;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		t[i] = t[i - 1] + a;
		mp[t[i]]++;
	}

	int res = 0;
	for (auto i : mp) {
		if (i.first == 0)
			res += (i.second * (i.second + 1)) / 2;
		else
			res += (i.second * (i.second - 1)) / 2;
	}
	cout << res;

	return 0;
}