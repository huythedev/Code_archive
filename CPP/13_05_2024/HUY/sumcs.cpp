#include <bits/stdc++.h>
using namespace std;

#define NAME "SUMCS"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int sumdigit(int n) {
	int res = 0;
	while(n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	docfile();

	int l, r, s; cin >> l >> r >> s;

	int res = 0;
	for(int i = l; i <= r; ++i)
		if(sumdigit(i) == s)
			++res;

	cout << res;
	return 0;
}
