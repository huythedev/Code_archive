#include <bits/stdc++.h>
using namespace std;

#define NAME "SEARCHX"
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

	int n, q; cin >> n >> q;

	map<int, int> freq;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		freq[t]++;
	}

	while (q--) {
		int x; cin >> x;

		if (freq[x] > 0)
			cout << "YES" << ln;
		else
			cout << "NO" << ln;
	}

	//cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}