#include <bits/stdc++.h>
using namespace std;

#define NAME "ODS"

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

int maxodddiv(int n) {
	if(n % 2 != 0)
		return n;
	for(int i = n / 2; i > 0; i--) {
		if((n % i) == 0 && (i % 2) != 0)
			return i;
	}
}

int main() {
	fastio(); docfile();

	int T; cin >> T;
	while(T--) {
		int A, B; cin >> A >> B;
		int res = 0;

		for(int i = A; i <= B; ++i)
			res += maxodddiv(i);
		cout << res << endl;
	}
	return 0;
}
