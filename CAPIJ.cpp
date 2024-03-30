#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<ll> vec(5 * 1e4 + 1);
	ll n;
	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		vec[i] = t;
	}
	
	ll Q;
	cin >> Q;
	
	while(Q--) {
		ll L, R;
		cin >> L >> R;
		
		L--; R--;
		ll res = 0;
		for(ll i = L; i < R; ++i) {
			for(ll j = i + 1; j <= R; ++j) {
				if(abs(vec[i] - vec[j]) > 1) {
					++res;
				}
			}
		}
		cout << res << endl;
	}
    return 0;
}