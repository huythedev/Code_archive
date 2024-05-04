#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t118vd2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MAXN = 60;
vector<ll> fib(MAXN);

void fibo() {
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < MAXN; ++i)
		fib[i] = fib[i - 2] + fib[i - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	fibo();

	int n; cin >> n;
	n--;

	cout << '[';
	for (int i = 0; i < n; ++i)
		cout << fib[i] << ", ";
	cout << fib[n] << ']';

	return 0;
}