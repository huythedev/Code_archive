#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1640"
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

	int n, x; cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];



	return 0;
}