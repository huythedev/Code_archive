#include <bits/stdc++.h>
using namespace std;

#define NAME "knapsack1"
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

	int N, W;
	cin >> N >> W;

	vector<int> weight(N), value(N);
	for (int i = 0; i < N; ++i)
		cin >> weight[i] >> value[i];

	vector<vector<ll> > dp(N + 1, vector<ll>(W + 1, 0LL));
	for (int i = 1; i <= N; ++i)
	{
		for (int w = 1; w <= W; ++w)
		{
			if (w >= weight[i - 1])
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + value[i - 1]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}

	cout << dp[N][W];

	return 0;
}