#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> prefixsum(vector <ll> arr) {
	vector <ll> res(arr.size() + 1);
	res[0] = 0;
	
	for (ll i = 0; i < arr.size(); ++i) {
		res[i + 1] = res[i] + arr[i];
	}
	
	return res;
}

int main() {
	ll N, Q;
	cin >> N >> Q;
	
	vector<ll> vec;
	while(N--) {
		ll n;
		cin >> n;
		vec.push_back(n);
	}
	
	while(Q--) {
		ll opt;
		cin >> opt;
		
		if (opt == 1) {
			ll l, r, k;
			cin >> l >> r >> k;
			l--;
			r--;
			ll n = k / (r -  + 1);
			for (ll i = l; i <= r; ++i) {
				vec[i] += n;
			}
		}
		else if (opt == 2) {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			for (ll n : vec) {
				cout << n << " ";
			}
			cout << endl;
			vector <ll> res = prefixsum(vec);
			
			ll sumres = 0;
			for (ll i = l; i <= r; ++i) {
				sumres += vec[i];
			}
			cout << sumres << endl;
		}
	}

    return 0;
}