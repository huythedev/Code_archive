#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t107vd2"
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

	double S = 0;
	for (int i = 1; i <= n; ++i)
		S += 1.0 / (i * i * i);

	cout << fixed << setprecision(5) << S;

	return 0;
}