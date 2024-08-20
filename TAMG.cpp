#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("TAMG.INP", "r", stdin);
	freopen("TAMG.OUT", "w", stdout);
}

bool checktg(ll a, ll b, ll c) {
	if (a+b>c && a+c>b && b+c>a) {
		return true;
	}
	return false;
}

int main() {
	docfile();
	ll n;
	vector<ll> arr;
	
	cin >> n;
	while(n--) {
		ll x;
		cin >> x;
		arr.push_back(x);
	}
	
	ll res = 0;
	for (ll i=0; i<arr.size() - 2; ++i) {
		for (ll j=i+1; j<arr.size() - 1; ++j) {
			for (ll k=j+1; k<arr.size(); ++k) {
				if (checktg(arr[i], arr[j], arr[k])) {
					++res;
				}
			}
		}
	}
	
	cout << res;
	
    return 0;
}