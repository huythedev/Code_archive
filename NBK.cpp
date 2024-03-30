#include <bits/stdc++.h>
using namespace std;

#define NAME "NBK"
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

	string st;
	getline(cin, st);
	
	for(ll i = 0; i < st.length(); ++i) {
		if(st[i] != 'N' && st[i] != 'B' && st[i] != 'K') {
			st.erase(i, 1);
			i--;
		}
	}	

	ll res = 0;
	for(ll i = 0; i < st.length() - 2; ++i) {
		if(st[i] == 'N') {
			for(ll j = i + 1; j < st.length() - 1; ++j) {
				if(st[j] == 'B') {
					for(ll k = j + 1; k < st.length(); ++k) {
						if(st[k] == 'K') 
							++res;
					}
				}
			}
		}
	}
	
	cout << res;
	
    return 0;
}