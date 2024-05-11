#include <bits/stdc++.h>
using namespace std;

#define NAME "absmax"
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

	int n; cin >> n;

	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	int a1 = INT_MIN, a2 = INT_MIN, b1 = INT_MAX, b2 = INT_MAX;

	for (int i : a)
		a1 = max(a1, i);

	for (int i : a)
		if (i > a2 && i < a1)
			a2 = i;

	for (int i : a)
		b1 = min(b1, i);

	for (int i : a)
		if (i < b2 && i > b1)
			b2 = i;

	cout << max(a1 + a2, abs(b1 + b2));

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}