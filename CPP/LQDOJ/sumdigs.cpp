#include <bits/stdc++.h>
using namespace std;

#define NAME "sumdigs"
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
		int n; cin >> n;
		int sumdig = 0;
		while (n) {
			sumdig += n % 10;
			n /= 10;
		}

		cout << sumdig << ln;
	}

	return 0;
}