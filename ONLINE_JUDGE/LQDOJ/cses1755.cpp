#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1755"
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

	string s, s1 = ""; cin >> s;
	char c, b;
	int i, a[130] = {}, d = 0, j, x;

	for (i = 0; i < s.size(); i++)
		a[s[i]]++;

	for (i = 60; i <= 125; i++)
		if (a[i] % 2 != 0)
			d++;

	if (d > 1) {
		cout << "NO SOLUTION";
		return 0;
	}

	for (i = 60; i <= 125; i++) {
		if (a[i] % 2 != 0) {
			b = char(i);
			x = i;
		}
		else if (a[i] % 2 == 0 && a[i] > 0) {
			c = char(i);
			for (j = 1; j <= a[i] / 2; j++)
				s1 += c;
		}
	}
	if (d == 0) {
		cout << s1;
		reverse(s1.begin(), s1.end());
		cout << s1;
		return 0;
	}

	cout << s1;
	for (i = 1; i <= a[x]; i++)
		cout << b;

	reverse(s1.begin(), s1.end());
	cout << s1;

	return 0;
}