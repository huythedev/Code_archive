#include <bits/stdc++.h>
using namespace std;

#define NAME "mabaimau"
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

	int idx = 0, maxnum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		if (maxnum < t) {
			maxnum = t;
			idx = i;
		}
	}

	cout << idx + 1;

	return 0;
}