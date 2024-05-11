#include <bits/stdc++.h>
using namespace std;

#define NAME "CHUANHOAXAU"
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

	while (st[0] == ' ')
		st.erase(0, 1);

	for (int i = 0; i < (int)st.length() - 1; ++i) {
		if (st[i + 1] == st[i] && st[i] == ' ') {
			st.erase(i, 1);
			i--;
		}
	}

	while (st[st.size() - 1] == ' ')
		st.erase(st.size() - 1, 1);

	cout << st;

	//cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}