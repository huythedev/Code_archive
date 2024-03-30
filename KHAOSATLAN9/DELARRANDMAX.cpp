#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	
	vector <ll> a;
	set <ll> t;
	while (n--) {
		ll tmp;
		cin >> tmp;
		a.push_back(tmp);
		t.insert(tmp);
	}
	
	ll res = 0;
	for (ll n : t) {
		vector <ll> t1 = a;
		for (ll i = 0; i < t1.size(); ++i) {
			if (t1[i] == n) {
				t1.erase(t1.begin() + i);
			}
			else if (t1[i] == (n - 1)) {
				t1.erase(t1.begin() + i);
			}
			else if (t1[i] == (n + 1)) {
				t1.erase(t1.begin() + i);
			}
		}
		ll tmp1 = 0;
		for (ll x : t1) {
			tmp1 += x;
		}
		res = max(tmp1, res);
	}
	
	cout << res;
    return 0;
}