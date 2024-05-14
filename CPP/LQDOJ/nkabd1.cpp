#include <bits/stdc++.h>
using namespace std;

int sumdiv(int n) {
	int res = 0;
	for(int i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			res += i;
			if(n / i != i)
				res += n / i;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L, R; cin >> L >> R;
	
	int res = 0;
	for(int i = L; i <= R; ++i)
		if(sumdiv(i) - i > i)
			++res;

	cout << res;
	return 0;
}
