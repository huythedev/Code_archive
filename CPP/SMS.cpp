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

	// 1 ki tu = 6 dong
	string st;
	getline(cin, st);
	
	ll sotien = 0;
	map<char, ll> freq;
	
	for(char c : st) {
		freq[tolower(c)]++;
		sotien += 18;
		cout << sotien << ln;
	}	
	
	ll khuyenmai = 0;
	for(auto &kv : freq) {
		ll tmp = kv.first;
		if(kv.second >= 2 && tmp - '0' > 9 && tmp - '0' < 0 || kv.second >= 2 && tmp != ' ') {
			khuyenmai += kv.second;
		}
		
		// cout << kv.first << " " << kv.second << ln;
	}
	
	cout << sotien << ln;

    return 0;
}