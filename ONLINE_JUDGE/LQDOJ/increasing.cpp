#include <bits/stdc++.h>
using namespace std;

#define NAME "increasing"
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
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a, a + n);

		bool tangnghiemngat = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[i - 1]) {
				cout << "NO" << ln;
				tangnghiemngat = false;
				break;
			}
		}

		if (tangnghiemngat)
			cout << "YES" << ln;
	}

	return 0;
}