#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string st;
	getline(cin, st);
	
	vector <ll> res;
	for (char c : st) {
		ll n = c - '0';
		if (n >= 0 && n <= 9) {
			res.push_back(n);
		}
	}
	
	sort(res.begin(), res.end());

	for (ll i = 0; i < res.size() - 1; ++i) {
		cout << res[i] << "+";
	}
	
	cout << res[res.size() - 1];
	
    return 0;
}
