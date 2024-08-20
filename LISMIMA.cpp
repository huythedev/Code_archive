#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, D;
	cin >> n >> D;
	
	vector<ll>a;
	ll t;
	while(cin >> t) {
		a.push_back(t);
	}
	
	ll res = 0;
	for(ll i = 0; i < n - 1; ++i) {
		for(ll j = i + 1; j < n; ++j) {
			ll tmp = *max_element(a.begin() + i, a.begin() + j);
			ll tmp1 = *min_element(a.begin() + i, a.begin() + j);
			if(tmp - tmp1 <= D) {
				if(tmp - tmp1 > res) {
					res = j - i + 1;
					if(res > a.size() - i) {
						cout << res;
						return 0;
					}
				}
			}
		}
	}

	cout << res;

    return 0;
}