#include <bits/stdc++.h>
using namespace std;

#define NAME "PALINMAX"
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

	int L = 0, R = st.length() - 1;
	int res = 0;
	for (int mid = 0; mid < st.length(); ++mid) {
		int length_1 = 0;
		while (mid - length_1 >= 0 && mid + length_1 < st.length() && st[mid - length_1] == st[mid + length_1])
			length_1++;

		int length_2 = 0;
		while (mid - length_2 >= 0 && mid + 1 + length_2 < st.length() && st[mid - length_2] == st[mid + 1 + length_2])
			length_2++;

		res = max(res, 2 * length_1 - 1);
		res = max(res, 2 * length_2);
	}

	cout << res;

	return 0;
}