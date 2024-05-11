#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool intersect(int a, int b, int c, int d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);

	if (a == c || a == d || b == c || b == d)
		return true;
	else if (a == 1 && b == 12 || c == 1 && d == 12 || a + 1 == b || c + 1 == d)
		return false;
	else {
		if (a < d && a > c) {
			if (b > d && )
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;

		if (intersect(a, b, c, d))
			cout << "YES" << ln;
		else
			cout << "NO" << ln;
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}