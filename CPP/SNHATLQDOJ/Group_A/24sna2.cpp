#include <bits/stdc++.h>
using namespace std;

#define NAME "24sna2"
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

	int T, D, Q, I; ll K; cin >> T >> D >> Q >> I >> K;

	if (D == I) {
		cout << abs(T - Q);
	}
	else {
		cout << abs((T + D * K) - (Q + I * K));
	}


	return 0;
}