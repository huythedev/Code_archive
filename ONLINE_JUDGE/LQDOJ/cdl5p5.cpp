#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl5p5"
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

	string st; getline(cin, st);

	int T; cin >> T;
	while (T--) {
		int L, R; cin >> L >> R;

		string s = st.substr(L, R - L);
		cout << s << ln;
	}

	return 0;
}