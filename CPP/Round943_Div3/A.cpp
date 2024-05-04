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
		int x; cin >> x;

		int maxval = 0, y = 0;
		for (int i = 1; i < x; ++i) {
			//cout << x << ' ' << i << ' ' << gcd(x, i) << ln;
			if (gcd(x, i) + i > maxval) {
				maxval = gcd(x, i) + i;
				y = i;
			}
		}

		cout << y << ln;
		//cout << "-------------" << ln;
	}

	return 0;
}