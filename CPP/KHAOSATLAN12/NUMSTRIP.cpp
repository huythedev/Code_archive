#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> buildprefixsum(vector<ll>a) {
    ll n = (ll)a.size();
    vector<ll> res(n + 1);

    res[0] = 0;

    for (ll i = 0; i < n; i++)
        res[i + 1] = res[i] + a[i];

    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	vector<ll> vec;
	while(n--) {
		ll t;
		cin >> t;
		vec.push_back(t);
	}
	
	vector<ll> prefixsum = buildprefixsum(vec);
	ll res = 0;
	for (ll i = 1; i < prefixsum.size() - 1; ++i) {
		if (prefixsum[i] == prefixsum[vec.size()] - prefixsum[i]) {
			++res;
		}
	}
	
	cout << res;
    return 0;
}