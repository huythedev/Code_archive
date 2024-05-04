#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1634"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MAXX = 1e6 + 6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n, x; cin >> n >> x;
	vector<int> c(101);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	vector<int> f(MAXX);
	f[0] = 0;
	for (int i = 1; i <= x; ++i) {
		f[i] = (int)1e9;
		for (int j = 1; j <= n; ++j) {
			if (i >= c[j])
				f[i] = min(f[i], f[i - c[j]] + 1);
		}
	}

	if (f[x] == (int)1e9)
		cout << -1;
	else
		cout << f[x];

	return 0;
}