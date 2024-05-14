#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, z; cin >> x >> y >> z;

	int a = (x + z - y) / 2, b = (x + y - z) / 2, c = (y + z - x) / 2;

	cout << a << ' ' << b << ' ' << c;

	return 0;
}
