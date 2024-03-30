#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("ZERO.INP", "r", stdin);
	freopen("ZERO.OUT", "w", stdout);
}

int main() {
	docfile();
	ll n;
	cin >> n;
	
	ll res = 0;
	while (n--) {
		ll t;
		cin >> t;
		if (t == 0) {
			++res;
		}
	}

	cout << res;
    return 0;
}