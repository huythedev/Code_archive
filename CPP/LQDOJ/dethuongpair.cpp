#include <bits/stdc++.h>
using namespace std;

#define NAME "dethuongpair"
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
	int minnum = INT_MAX, maxnum = INT_MIN, minnum_pos, maxnum_pos;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] >= maxnum) {
			maxnum = a[i];
			maxnum_pos = i;
		}
		if (a[i - 1] < minnum) {
			minnum = a[i];
			minnum_pos = i;
		}
	}

	cout << minnum_pos + 1 << ' ' << maxnum_pos + 1 << ln;
	cout << maxnum - minnum;

	return 0;
}