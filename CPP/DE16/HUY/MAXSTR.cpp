#include <bits/stdc++.h>
using namespace std;

#define NAME "MAXSTR"

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	fastio();
	docfile();

	int index = 1, maxstring_index = 0, maxlength = 0;
	string S, maxstring;

	while(getline(cin, S)) {
		if(S.size() > maxlength) {
			maxlength = S.size();
			maxstring_index = index;
			maxstring = S;
		}
		++index;
		cin >> ws;
	}

	cout << "dong: " << maxstring_index << endl;
	cout << maxstring << endl;
	cout << "Do dai dong: " << maxlength;

	return 0;
}
