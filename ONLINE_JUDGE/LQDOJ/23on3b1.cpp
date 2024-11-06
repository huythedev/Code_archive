#include <bits/stdc++.h>
using namespace std;

#define NAME "23on3b1"
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

	ll N, C, S; cin >> N >> C >> S;

	cout << N * C - N / 15 * S;

	return 0;
}