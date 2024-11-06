#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1618"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int demso0(int n) {
	int res = 0;

	for (int i = 5; n / i >= 1; i *= 5)
		res += n / i;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;
	cout << demso0(n);

	return 0;
}