#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> ptts(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
    	if(n % i == 0) {
    		res.push_back(i);
    	}
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	vector<ll> thuaso = ptts(n);
	
	if(thuaso.size() == 1 && thuaso[0] > 1) {
		cout << "-1";
		return 0;
	}
	
	ll res = 1;
	for(ll n : thuaso) {
		res *= n;
	}
	cout << res;

    return 0;
}