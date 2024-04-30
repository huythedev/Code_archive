#include <bits/stdc++.h>
using namespace std;

#define NAME "mcd"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int sumcs(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int a, b; cin >> a >> b;

	int res = 0;
	for (int i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			if (b % i == 0)
				res = max(res, sumcs(i));
			if (b % (a / i) == 0)
				res = max(res, sumcs(a / i));
		}
	}

	cout << res;

	return 0;
}