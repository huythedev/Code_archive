#include <bits/stdc++.h>
using namespace std;

#define NAME "22stra2"
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

	ll a, b, c, d; cin >> a >> b >> c >> d;

	cout << a - d;

	return 0;
}