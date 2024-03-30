#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	n *= 2;
	--n;
	
	ll res = -1e9;
	while(n--) {
		ll t;
		cin >> t;
		res += t;
	}
	res += 1e9;
	
	if (res < 0) {
		cout << "1" << endl << abs(res);
	}
	else {
		cout << "-1" << endl << res;
	}
	
	return 0;
}
