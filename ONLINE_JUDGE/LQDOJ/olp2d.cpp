#include <bits/stdc++.h>
using namespace std;

#define NAME "olp2d"
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

	int n, d; cin >> n >> d;
	vector<int> c(2 * n);
	for (int &i : c)
		cin >> i;

	sort(c.begin(), c.end());

	vector<int> dp(2 * n + 1, INT_MIN);
	dp[0] = 0;

	for (int i = 1; i <= 2 * n; ++i) {
		for (int j = max(0, i - 2 * n); j < i; ++j) {
			if (abs(c[i - 1] - c[j]) <= d) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int max_students = *max_element(dp.begin(), dp.end());
	cout << max_students << endl;

	return 0;
}