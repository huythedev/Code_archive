#include <bits/stdc++.h>
using namespace std;

#define NAME "cntpair0sum"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll N;
	cin >> N;
	map<ll, ll> freq;

	ll res = 0;
	for (ll i = 0; i < N; ++i) {
		ll num;
		cin >> num;
		res += freq[-num];
		freq[num]++;
	}

	cout << res;

	return 0;
}