#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n; cin >> m >> n;

	cout << (n + 1) * m + (m + 1) * n;
	return 0;
}
