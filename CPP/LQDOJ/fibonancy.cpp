#include <bits/stdc++.h>
using namespace std;

#define NAME "fibonancy"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool ischinhphuong(ll x) {
	ll s = sqrt(x);
	return s * s == x;
}

bool isFib(ll n) {
	return ischinhphuong(5LL * n * n + 4) || ischinhphuong(5LL * n * n - 4);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int T; cin >> T;
	while (T--) {
		ll N; cin >> N;
		if (isFib(N))
			cout << "IsFibo" << ln;
		else
			cout << "IsNotFibo" << ln;
	}

	return 0;
}
//AC using python