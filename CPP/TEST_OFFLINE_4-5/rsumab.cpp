#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> buildprefixsum(vector<ll> vec) {
	vector<ll> res((int)vec.size() + 1);
	res[0] = 0;
	for(int i = 1; i < (int)res.size(); ++i)
		res[i] = res[i - 1] + vec[i - 1];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;

	vector<ll> x(n);
	for(int i = 0; i < n; ++i)
		cin >> x[i]; 
		
	vector<ll> prefixsum = buildprefixsum(x);		

	while(q--) {
		int type; cin >> type;
		if(type == 1) {
			int pos, val; cin >> pos >> val;
			
			ll diff = val - x[pos - 1];
			
			for(int i = pos; i < (int)prefixsum.size(); ++i)
				prefixsum[i] += diff;
			x[pos - 1] = val;
		}
		else {
			int l, r; cin >> l >> r;
			cout << prefixsum[r] - prefixsum[l - 1] << endl;
		}
	}
	return 0;
}
