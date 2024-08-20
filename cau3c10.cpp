#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
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
	
	vector<ll> vec(N);
	for(ll i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	
	ll Q = __gcd(vec[0], vec[1]);
	for(ll i = 2; i < N; ++i) {
		Q = __gcd(Q, vec[i]);
	}
	
	cout << Q;

    return 0;
}