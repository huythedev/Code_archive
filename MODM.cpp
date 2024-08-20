#include <bits/stdc++.h>
using namespace std;

#define NAME "MODM"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

ll multiply(ll num1, ll num2, ll m) {
	ll result = 0;
	while (num1 > 0) {
		if (num1 % 2 == 1)
			result = (result + num2) % m;
		num1 >>= 1;
		num2 = (num2 * 2) % m;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll a, b, m;
	cin >> a >> b >> m;

	cout << multiply(a, b, m);

	return 0;
}