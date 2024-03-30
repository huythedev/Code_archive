#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, k;
	vector <ll> vec;
	
	cin >> n;
	while (n--) {
		ll t;
		cin >> t;
		vec.push_back(t);
	}
	cin >> k;
	
	vector <ll> res;
	for (ll i = 0; i < vec.size(); ++i) {
		if (vec[i] == k) {
			res.push_back(i);
		}
	}
	
	if (res.size() == 0) {
		cout << "-1";
	}
	else {
		for (ll n : res) {
			cout << n + 1 << " ";
		}
	}
    return 0;
}