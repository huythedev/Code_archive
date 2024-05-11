#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;

		bool impossible = true;
		for (int i = 1; i < s.length(); ++i)
			if (s[i] != s[i - 1])
				impossible = false;

		if (!impossible) {
			bool tmp = false;
			for (int i = 0; i < s.length() - 1; ++i) {
				for (int j = i + 1; j < s.length(); ++j)
					if (s[i] != s[j]) {
						swap(s[i], s[j]);
						tmp = true;
						break;
					}
				if (tmp)
					break;
			}
		}

		if (impossible)
			cout << "NO" << ln;
		else {
			cout << "YES" << ln << s << ln;
		}
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}