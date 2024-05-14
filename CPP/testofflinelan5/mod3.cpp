#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int L, R; cin >> L >> R;

	cout << (R / 3) - (L - 1) / 3;

	return 0;
}
