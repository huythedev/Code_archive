#include <bits/stdc++.h>
using namespace std;

#define NAME "oddeven"
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

	int N; cin >> N;
	while (N--) {
		string s; cin >> s;

		bool ok = true;
		for (int i = 0; i < s.size(); ++i) {
			if ((i + 1) % 2 == 0) {
				if ((s[i] - '0') % 2 != 0) {
					ok = false;
					break;
				}
			}

			else {
				if ((s[i] - '0') % 2 == 0) {
					ok = false;
					break;
				}
			}

		}

		if (ok)
			cout << "YES";
		else
			cout << "NO";

		cout << ln;
	}

	return 0;
}