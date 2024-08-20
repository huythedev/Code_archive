#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	unordered_map<ll, ll> freq;
	
	for(ll i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		freq[t]++;
	}
	
	ll res = 0;
	for(auto tmp : freq) {
		res += tmp.second / 2;
	}
	
	cout << res;

    return 0;
}