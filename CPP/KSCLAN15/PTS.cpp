#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	for(ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= n; ++j) {
			if (n == (i + 1) * (2 * j + i) / 2) {
				cout << j - i - 2;
				return 0;
			}
		}
	}
	
	cout << "0";
    return 0;
}
//(k + 1)(2n + k) / 2