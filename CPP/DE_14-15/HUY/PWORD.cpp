#include <bits/stdc++.h>
using namespace std;

#define NAME "PWORD"

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

bool isDigit(char c) {
	return (c - '0' >= 0 && c - '0' <= 9);
}

int main() {
	fastio(); docfile();

	string S; getline(cin, S);

	int res = 0;
	for(char c : S)
		if(isDigit(c))
			res += c - '0';

	cout << res;
	return 0;
}
