#include <bits/stdc++.h>
using namespace std;

#define NAME "QUADRUPLE"
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
	
	vector<ll> a(N);
	for(ll i = 0; i < N; ++i) 
		cin >> a[i];
		
	ll res = 0;
	for(ll i = 0; i < N - 3; ++i) {
		for(ll j = i + 1; j < N - 2; ++j) {
			for(ll p = j + 1; p < N - 1; ++p) {
				for(ll q = p + 1; q < N; ++q) {
					if(a[i] - a[j] == a[p] - a[q]) 
						++res;
 				}
			}
		}
	}
	
	cout << res;

    return 0;
}