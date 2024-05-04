#include <bits/stdc++.h>
using namespace std;

#define NAME "divisorscr"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

pair<int, int> sumdiv(int n) {
	int sumdiv = 0, div = 0;;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			sumdiv += i;
			++div;
			if (i != n / i) {
				sumdiv += n / i;
				++div;
			}
		}
	}
	return {div, sumdiv};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int N; cin >> N;
	pair<int, int> res = sumdiv(N);

	cout << res.first << ' ' << res.second;

	return 0;
}