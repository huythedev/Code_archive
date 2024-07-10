#include <bits/stdc++.h>
using namespace std;

#define NAME "TOTAL"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool isDig(char c) {
	return (c - '0') >= 0 && (c - '0') <= 9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	docfile();

	string s; getline(cin, s);

	int res = 0;
	for(char c : s)
		if(isDig(c))
			res += c - '0';

	cout << res;
	return 0;
}
