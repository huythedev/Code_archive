#include <bits/stdc++.h>
using namespace std;

#define NAME "maxarr01"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MAXN = 1e5;
int a[MAXN + 1], f[MAXN + 1];

void build() {
	a[0] = 0;
	a[1] = 1;
	f[0] = 0;

	for (int i = 1; i <= MAXN / 2; i++) {
		a[2 * i] = a[i];
		a[i * 2 + 1] = a[i] + a[i + 1];
	}

	for (int i = 1; i <= MAXN; i++)
		f[i] = max(f[i - 1], a[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	build();

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << f[n] << ln;
	}

	return 0;
}