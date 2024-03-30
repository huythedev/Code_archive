#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 2 * 1e5;
ll freq[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, k;
	cin >> n >> k;

  	vector<ll> vec;
  	ll t, nhonhat = LLONG_MAX, res = 0;
  	while(cin >> t) {
  		vec.push_back(t);
  		freq[t]++;
  		nhonhat = min(nhonhat, t);
  		res += t;
  	}
  	
  	res -= nhonhat;
  	++n;
  	while(n--) {
  		if(freq[n] == 0) {
  			res += n;
  			break;
  		}
  	}
  	
  	cout << res;
	return 0;
}