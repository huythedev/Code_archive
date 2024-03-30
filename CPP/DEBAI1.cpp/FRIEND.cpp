#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumgcd(ll b) {
	ll SumGCDb = 0;
	
	for (ll i = 1; i < b; ++i) {
		if(b % i == 0) {
			SumGCDb += i;
		}
	}
	
	return SumGCDb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll a, b;
	cin >> a >> b;
	
	for(ll i = a; i < b; ++i) {
		ll SumGCDa = 0;
		for (ll j = 1; j < a; ++j) {
			if(a % j == 0) {
				SumGCDa += j;
			}
		}
		
		for(ll j = a + 1; j <= b; ++j) {
			if(sumgcd(j) == SumGCDa) {
				cout << i << j << endl;
			}
		}
	}
	

    return 0;
}