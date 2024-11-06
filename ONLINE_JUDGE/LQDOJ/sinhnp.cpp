#include <bits/stdc++.h>
using namespace std;

#define NAME "sinhnp"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int x[20];

void xuly(int i, int n) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			for (int i = 1; i <= n; i++)
				cout << x[i];
			cout << ln;
		}
		else
			xuly(i + 1, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;
	xuly(1, n);

	return 0;
}