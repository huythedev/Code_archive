#include <bits/stdc++.h>
using namespace std;

#define NAME "cntle"
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

	string st; cin >> st;

	int res = 0;
	for (char c : st)
		if (c - '0' >= 0 && c - '0' <= 9)
			if ((c - '0') % 2 != 0) ++res;

	cout << res;

	return 0;
}