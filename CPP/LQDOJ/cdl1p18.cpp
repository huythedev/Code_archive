#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl1p18"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const double g = 9.8;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	double h; cin >> h;

	cout << fixed << setprecision(2) << sqrt(2 * g * h);

	return 0;
}