#include <bits/stdc++.h>
using namespace std;

#define NAME "vacation"
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

	int N; cin >> N;
	vector<int> a(N + 1), b(N + 1), c(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> a[i] >> b[i] >> c[i];

	int dp[N + 1][3];
	dp[1][0] = a[1];
	dp[1][1] = b[1];
	dp[1][2] = c[1];
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = b[i] + max(dp[i - 1][2], dp[i - 1][0]);
		dp[i][2] = c[i] + max(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << max(dp[N][0], max(dp[N][1], dp[N][2]));

	return 0;
}