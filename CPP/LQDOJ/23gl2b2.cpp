#include <bits/stdc++.h>
using namespace std;

#define NAME "23gl2b2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int N; cin >> N;
	vector<int> a(N + 5);
	for (int i = 1; i <= N; i++)
		cin >> a[i];

	vector<int> t(N + 5, 0);
	for (int i = N; i >= 1; i--)
		t[i] = (t[i + 1] + a[i]) % MOD;

	int res = 0;
	for (int i = 1; i <= N; i++)
		res = (res + (1LL * a[i] * t[i + 1]) % MOD) % MOD;

	cout << res;

	return 0;
}