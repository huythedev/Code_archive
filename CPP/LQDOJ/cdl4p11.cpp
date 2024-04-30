#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl4p11"
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

	int a, b; cin >> a >> b;

	cout << fixed << setprecision(2) << -b / float(a);

	return 0;
}