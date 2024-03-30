#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("COUNT.INP", "r", stdin);
	freopen("COUNT.OUT", "w", stdout);
}

int main() {
	docfile();
	string st;
	getline(cin, st);
	
	set<char> res;
	for (char c : st) {
		res.insert(c);
	}
	
	cout << res.size();
    return 0;
}