#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll n) {
	ll res = 0;
	for (ll i = 1; i <= n; ++i) {
		if (i % 2 == 0) {
			res += i * i;
		}
		else {
			res -= i * i;
		}
	}
	return res;
}

int main() {
	vector <ll> tests;
	
	
	ll T;
	cin >> T;
	
	while(T--) {
		ll n;
		cin >> n;
		tests.push_back(n);
	}
	
	for (ll n : tests) {
		cout <<  pow(-1, (n + 1)) * (n * n)  << endl;
	}

    return 0;
}