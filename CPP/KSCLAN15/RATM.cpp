#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, k;
	cin >> n >> k;
	
	vector<ll> vec;
	while(n--) {
		ll t;
		cin >> t;
		vec.push_back(t);
	}
	
	string res = "";
	
	for(ll n : vec) {
		if (k - n >= 0) {
			res += to_string(1);
			k -= n;
		}
		else {
			res += to_string(0);
		}
	}
	
	cout << res;

    return 0;
}