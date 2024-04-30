#include <bits/stdc++.h>
using namespace std;

#define NAME "cdl6p10"
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

	vector<int> a;
	int t;
	while (cin >> t)
		a.push_back(t);

	int res = 0;
	for (int i = 1; i < a.size() - 1; ++i)
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			++res;

	cout << res;

	return 0;
}