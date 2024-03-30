#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> prefixsum(vector <ll> vec) {
	ll tmp = vec.size();
	vector <ll> res(tmp + 1);
	int C = 0;
	res[0] = C;
	for (ll i = 0; i < vec.size(); ++i) {
		res[i + 1] = (res[i] + vec[i]);
	}
	
	return res;
}

int main() {

	ll n, k;
	cin >> n >> k;
	
	vector <ll> tmp;
	while(n--) {
		ll t;
		cin >> t;
		tmp.push_back(t);
	}
	
	vector <ll> vec = prefixsum(tmp);
	ll res = 0;
	
	for (ll r = 0; r < vec.size(); ++r) {
		for (ll l = 0; l <= r; ++l) {
			if(vec[r + 1] - vec[l]) {
				++res;
			}
		}
	}
	
	cout << res << endl;
    return 0;
}