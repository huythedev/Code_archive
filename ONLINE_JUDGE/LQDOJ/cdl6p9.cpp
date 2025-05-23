#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl6p9"
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

	int n;
	while (cin >> n)
		if (n < 0)
			cout << -1 << ' ';
		else if (n > 0)
			cout << 1 << ' ';
		else
			cout << 0 << ' ';

	return 0;
}