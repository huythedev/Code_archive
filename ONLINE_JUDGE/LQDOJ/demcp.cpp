#include <bits/stdc++.h>
using namespace std;

#define NAME "demcp"
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

	ll L, R; cin >> L >> R;

	int lower = ceil(sqrt(L));
	int upper = floor(sqrt(R));

	cout << upper - lower + 1;

	return 0;
}