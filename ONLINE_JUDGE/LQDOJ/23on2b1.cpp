#include <bits/stdc++.h>
using namespace std;

#define NAME "23on2b1"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	string S; getline(cin, S);

	for (int i = 0; i < S.length(); ++i) {
		if ((i + 1) % 2 != 0) {
			if (S[i] != tolower(S[i])) {
				cout << "No";
				return 0;
			}
		}
		else {
			if (S[i] != toupper(S[i])) {
				cout << "No";
				return 0;
			}
		}
	}

	cout << "Yes";

	return 0;
}