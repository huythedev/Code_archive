#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("PTICH.INP", "r", stdin);
	freopen("PTICH.OUT", "w", stdout);
}

vector <pair <ll, ll> > thuasonguyento(ll n) {
	vector<pair <ll, ll> > res;
	for (ll i = 2; i * i <= n; ++i) {
		ll t = 0;
		while (n % i == 0) {
			n /= i;
			++t;
		}
		res.push_back(make_pair(i, t));
	}
	
	if (n != 1) {
		res.push_back(make_pair(n, 1));
	}
	
	return res;
}

int main() {
	docfile();
	ll n;
	cin >> n;
	vector<pair <ll, ll> > arr = thuasonguyento(n);
	for (ll i = 0; i < arr.size(); ++i) {
		cout << arr[i].first << " " << arr[i].second << endl; 
	}

    return 0;
}