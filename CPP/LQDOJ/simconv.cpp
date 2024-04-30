#include <bits/stdc++.h>
using namespace std;

#define NAME "simconv"
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

	int tests; cin >> tests;

	while (tests--) {
		int n; cin >> n;
		cout << n * 3153600000 << ln;
	}

	return 0;
}