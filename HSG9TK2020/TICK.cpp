#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll N;
	vector<ll> t, r;

	cin >> N;
	for(ll i = 0; i < N; ++i) {
		ll x;
		cin >> x;
		t.push_back(x);
	}

	for(ll i = 0; i < N - 1; ++i) {
		ll x;
		cin >> x;
		r.push_back(x);
	}

	

    return 0;
}