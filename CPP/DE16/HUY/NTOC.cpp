#include <bits/stdc++.h>
using namespace std;

#define NAME "NTOC"

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool isPrime(int n) {
	if(n == 2 || n == 3)
		return true;
	if(n < 3 || n % 2 == 0 || n % 3 == 0)
		return false;
	for(int i = 5; i * i <= n; i += 6)
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

int main() {
	fastio();
	docfile();

	string S; cin >> S;

	int res = 0;
	for(char c : S)
		if(isPrime(c - '0'))
			res += c - '0';
	cout << res;
	return 0;
}
