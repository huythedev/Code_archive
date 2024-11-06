#include <bits/stdc++.h>
using namespace std;

#define NAME "kntt10t118vd1"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;

	int tmp = 2;
	cout << '[';
	for (int i = 0; i < n - 1; ++i) {
		cout << tmp << ", ";
		tmp += 2;
	}

	cout << tmp;
	cout << ']';

	return 0;
}