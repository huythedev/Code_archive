#include <bits/stdc++.h>
using namespace std;

int cntdiv(int n) {
	int res = 0;
	for(int i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			++res;
			if(n / i != i)
				++res;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	while(n--) {
		int x; cin >> x;

		cout << cntdiv(x) << endl;
	}

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}

