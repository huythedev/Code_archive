#include <bits/stdc++.h>
using namespace std;

#define NAME "GIFT1"
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

	map<int, int> freq;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		freq[t]++;
	}

	cout << freq.size();

	//cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}