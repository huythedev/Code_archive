#include <bits/stdc++.h>
using namespace std;

#define NAME "23thtltabnia4"
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

	int N; cin >> N;

	ll res = 0;
	if (N % 9 == 0)
		res -= N;

	while (N % 9 != 0)
		--N;

	int i = 1;
	while (i * 9 <= N) {
		res += i * 9;
		++i;

	}
	cout << res;

	return 0;
}