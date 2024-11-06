#include <bits/stdc++.h>
using namespace std;

#define NAME "fibo"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int fib[50];

void pre_calc() {
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i < 50; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	pre_calc();

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;

		cout << fib[n - 1] << ln;
	}

	return 0;
}