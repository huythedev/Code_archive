#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string st;
	getline(cin, st);
	
	ll res = 0;
	if (st[0] != ' ') {
		++res;
	}
	for (ll i = 1; i < st.length(); ++i) {
		if (st[i - 1] == ' ' && st[i] != ' ') {
			++res;
		}
	}
	
	cout << res;
    return 0;
}