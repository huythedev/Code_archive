#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl2p10"
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

	int a, b, d1, d2, d3, x; cin >> a >> b >> d1 >> d2 >> d3 >> x;

	if (x <= a)
		cout << x * d1;
	else if (x <= b)
		cout << a * d1 + (x - a) * d2;
	else
		cout << a * d1 + (b - a) * d2 + (x - b) * d3;

	return 0;
}