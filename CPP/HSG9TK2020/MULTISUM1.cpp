#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll sumcs(ll n) {
	ll res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll K, D;
	cin >> K >> D;
	
	ll res = 0;
	for (ll i = 1; i <= K; ++i) {
		if (sumcs(i) % D == 0) {
			res = (res + 1) % MOD;
		}
	}
	
	cout << res;

    return 0;
}