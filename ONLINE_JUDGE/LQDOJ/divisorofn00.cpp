#include <bits/stdc++.h>
using namespace std;

#define NAME "divisorofn00"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

vector<int> div(int n) {
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i)
				res.push_back(n / i);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;

	vector<int> vec = div(n);
	sort(vec.begin(), vec.end());
	for (int i : vec)
		cout << i << ' ';

	return 0;
}