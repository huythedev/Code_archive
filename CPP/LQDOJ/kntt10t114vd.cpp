#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t114vd"
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

	int maxnum = INT_MIN, maxnum_pos = 0;
	int curr_pos = 0;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		if (t > maxnum) {
			maxnum = t;
			maxnum_pos = curr_pos;
		}

		++curr_pos;
	}

	cout << "Giá trị lớn nhất của dãy A: " << maxnum << ln << "Chỉ số là: " << maxnum_pos;

	return 0;
}