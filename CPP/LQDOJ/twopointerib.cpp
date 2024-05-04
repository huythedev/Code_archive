#include <bits/stdc++.h>
using namespace std;

#define NAME "twopointerib"
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

	int n, m; cin >> n >> m;

	vector<int> a(n), b(m);
	for (int &i : a)
		cin >> i;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];

		auto tmp = lower_bound(a.begin(), a.end(), b[i]);
		cout << tmp - a.begin() << ' ';
	}

	return 0;
}