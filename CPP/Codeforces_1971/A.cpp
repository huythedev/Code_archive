#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

	int t; cin >> t;
	while (t--) {
		int x, y; cin >> x >> y;

		if (x > y)
			swap(x, y);
		cout << x << ' ' << y << ln;
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}