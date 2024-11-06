#include <bits/stdc++.h>
using namespace std;

#define NAME "lop2a"
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

	ld a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;

	if (a1 / b1 == a2 / b2 || a1 / b1 == b2 / a2)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}