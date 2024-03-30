#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("BANGSO.INP", "r", stdin);
	freopen("BANGSO.OUT", "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	ll M, N;
	cin >> M >> N;
	vector<ll> vec;
	ll t;
	while(cin >> t) {
		vec.push_back(t);
	}
	
	sort(vec.begin(), vec.end());
	
	ll tmp = 0;
	bool tmp1 = true;
	for(ll i = 0; i < M; ++i) {
		if(tmp1) {
			for(ll j = 0; j < N; ++j) {
				cout << vec[tmp] << " ";
				++tmp;
			}
			tmp1 = false;
		}
		else {
			tmp += N - 1;
			for(ll j = 0; j < N; ++j) {
				cout << vec[tmp] << " ";
				--tmp;
			}
			tmp += N + 1;
			tmp1 = true;
		}
		
		cout << endl;
	}
}