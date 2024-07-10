#include <bits/stdc++.h>
using namespace std;

#define NAME "PHANLOAI"

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
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	string S; getline(cin, S);

	int sumdig = 0;
	for(char c : S)
		if(isDig(c))
			sumdig += c - '0';
		else
			cout << c;

	cout << endl << sumdig;
	return 0;
}
