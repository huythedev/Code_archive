#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl5p6"
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
	int Q; cin >> Q;
	while (Q--) {
		string st; cin >> st;
		size_t it = S.find(st);
		if (it != string::npos) {
			cout << it << ln;
		}
		else
			cout << -1 << ln;
	}

	return 0;
}