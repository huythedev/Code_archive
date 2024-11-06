#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t104vd1"
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

	int m; cin >> m;

	if (m < 5)
		cout << m * 12000;
	else
		cout << m * 10000;

	return 0;
}