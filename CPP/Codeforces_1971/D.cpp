#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int minPieces(const string& s) {
	int pieces = 1;
	char prev = '0';
	for (char c : s) {
		if (c != prev) {
			pieces++;
			prev = c;
		}
	}
	if (prev == '1') {
		pieces--;
	}
	return pieces;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << minPieces(s) << endl;
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}