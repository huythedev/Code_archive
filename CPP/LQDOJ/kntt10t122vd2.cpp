#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t122vd2"
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

	int n; cin >> n;
	int res = 0;
	while (n--) {
		string st; getline(cin, st);
		cin >> ws;

		int i = st.length() - 1;
		for (i; i >= 0; --i)
			if (st[i] == ' ')
				break;

		string tmp = st.substr(i + 1);
		if (tmp == "Hương")
			++res;
	}

	cout << res;

	return 0;
}