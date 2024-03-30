#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	cin >> N;
	
	vector<ll> vec;
	ll t;
	while(cin >> t) {
		vec.push_back(t);
	}
	
	ll res = 0;
	for(ll i = 0; i < vec.size() - 1; ++i) {
		ld tmp1 = (vec[i] + vec[i + 1]) / 2.0;
		ld tmp2 = sqrt(vec[i] * vec[i + 1]);
		if (tmp1 > tmp2) {
			++res;
		}
	}

	cout << res;
    return 0;
}