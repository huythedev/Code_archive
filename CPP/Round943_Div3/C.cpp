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

vector<int> findArray(int n, vector<int>& x) {
	vector<int> a(n);
	a[0] = 1; // Arbitrarily choose a value for a1

	// Calculate a2, ..., an based on the given values x2, ..., xn
	for (int i = 1; i < n; ++i) {
		a[i] = a[i - 1] + x[i - 1];
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x(n - 1);
		for (int &i : x)
			cin >> i;

		vector<int> a = findArray(n, x);
		for (int i : a)
			cout << i << ' ';
		cout << ln;
	}

	return 0;
}