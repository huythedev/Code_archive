#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	ll d = max(a,(max(b,c))) - min(a,(min(b,c))); 
	
	for (ll i = 1; i * i <= d; ++i) {
		if (d % i == 0) {
			if (a % i == b % i && b % i == c % i) {
				cout << i;
				return 0;
			}

			if (i != d / i && a % (d / i) == b % (d / i) && b % (d / i) == c % (d / i)) {
				cout << d / i;
				return 0;
			}
		}
	}

    return 0;
}
