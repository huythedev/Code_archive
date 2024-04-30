#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1095"
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

ll powmod(int a, int b) {
	ll d, res = 1, d1;
	while (b > 1) {
		d = a; d1 = 1;

		while (d1 <= b / 2) {
			d = (d * d) % MOD; d1 = d1 * 2;
		}

		b = b - d1;
		res = (res * d) % MOD;
	}

	if (b == 1)
		res = (res * a) % MOD;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		cout << powmod(a, b) << ln;
	}

	return 0;

}