#include <bits/stdc++.h>
using namespace std;

#define NAME "d13easytask"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MAXN = 1000000 + 5;
bool isPrime[MAXN];

void sieve() {
	for (int i = 0; i <= MAXN; ++i)
		isPrime[i] = true;

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= MAXN; ++i) {
		if (isPrime[i])
			for (int j = i * i; j <= MAXN; j += i)
				isPrime[j] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	sieve();

	int n; cin >> n;

	ll prefixsum = 0, min_val = LLONG_MAX, res = LLONG_MIN;

	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		prefixsum += a;

		if (isPrime[i + 1])
			res = max(res, prefixsum - min_val);

		if (isPrime[i + 2])
			min_val = min(min_val, prefixsum);
	}

	cout << res;

	return 0;
}