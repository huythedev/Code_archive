#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	vector<ll> a, b;
	cin >> t;
	while (t--) {
		ll a1, b1;
		cin >> a1 >> b1;
		a.push_back(a1);
		b.push_back(b1);
	}
	
	for (ll i = 0; i < a.size(); ++i) {
		ll res = 0;
		while (a[i] != 0 || b[i] != 0) {
			if (a[i] > b[i]) {
				a[i] -= b[i];
				++res;
			}
			else {
				b[i] -= a[i];
				++res;
			}
			if (a[i] == 0 || b[i] == 0) {
				break;
			}
		}
		cout << res << endl;
	}

    return 0;
}