#include <bits/stdc++.h>
using namespace std;

#define NAME "notright"
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

	int T; cin >> T;
	while (T--) {
		ll a, b, c; cin >> a >> b >> c;

		if (a + b <= c || b + c <= a || a + c <= b) {
			cout << "NO" << ln;
			continue;
		}

		a *= a; b *= b; c *= c;
		if (a == b + c || b == a + c || c == a + b)
			cout << "NO";
		else
			cout << "YES";

		cout << ln;
	}

	return 0;
}