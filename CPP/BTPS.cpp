#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long double tinh (long long x) {
	long double res = 0;
	for (long long i = 0; i <= 2 * x; i += 2) {
		res += 1.0/((i + 1)*(i + 3));
	}
	return res;
}

int main() {
	
	long long k;
	cin >> k;
	long double res = tinh(k);
	cout << fixed << setprecision(10) << res;

    return 0;
}