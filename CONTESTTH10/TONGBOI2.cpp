#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll l, r, k, res = 0;
	cin >> l >> r >> k;
	
	ll tmp = 1;
	while ((tmp * k) <= r) {
		if ((tmp * k) >= l) {
			res += tmp * k;
		}
		++tmp;
	}
	
	cout << res;
    return 0;
}