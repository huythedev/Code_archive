#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
	
		ll res = 0;
		for (ll i = 0; i < y; ++i) {
			ll t = __gcd(x, y);
			if (__gcd(x + i, y) == t) {
				++res;
			}
		}
	
		cout << res << endl;
	}

    return 0;
}