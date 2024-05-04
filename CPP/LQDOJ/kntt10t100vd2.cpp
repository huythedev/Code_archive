#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t100vd2"
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

	double a, b, c; cin >> a >> b >> c;
	double p = (a + b + c) / 2;
	double dientich = sqrt(p * (p - a) * (p - b) * (p - c));

	cout << "Chu vi = " << a + b + c << ln << "Diện tích = " << fixed << setprecision(3) << dientich;

	return 0;
}