#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool checkcp(ld n) {
	ll tmp = sqrt(n);
	if (tmp * tmp == n) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll x;
	cin >> x;

	for (ll i = 1; i <= x - 1; ++i) {
		if(checkcp(x / float(i))) {
			cout << sqrt(x / i);
			return 0;
		}
	}

	cout << "1";

    return 0;
}