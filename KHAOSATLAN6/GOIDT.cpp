#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, x, b, y, k;
	cin >> a >> x >> b >> y >> k;

	if (k > a) {
		k -= a;
		a = 0;
	}
	else {
		a -= k;
		k = 0;
	}

	if (k > b) {
		k -= b;
		b = 0;
	}
	else {
		b -= k;
		k = 0;
	}

	cout << a*x + b*y;
	return 0;
}