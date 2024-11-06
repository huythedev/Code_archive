#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl5p10"
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

	string s; getline(cin, s);
	char del; cin >> del;

	for (char c : s)
		if (c != del) cout << c;

	return 0;
}