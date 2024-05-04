#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t110lt2"
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

	int res = 0;
	for (int i = 100; i >= 0; ++i)
		if (i % 5 == 0 || i % 3 == 1)
			++res;

	cout << res;

	return 0;
}