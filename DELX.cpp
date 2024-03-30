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

	ll N, x;
	cin >> N >> x;
	
	vector<ll> a(N);
	for(ll i = 0; i < N; ++i) 
		cin >> a[i];
		
	bool found = false;
	for(ll i = 0; i < N; ++i) {
		if(a[i] == x) {
			a.erase(a.begin() + i);
			i--;
			found = true;
		}
	}
	
	if(found) {
		for(ll n : a) {
			cout << n << " ";
		}
	}
	else {
		cout << -1;
	}

    return 0;
}