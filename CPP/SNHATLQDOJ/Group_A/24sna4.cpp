#include <bits/stdc++.h>
using namespace std;

#define NAME "24sna4"
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

	int n, d; cin >> n >> d;
	vector<int> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int res = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (s.size() < 2)
			break;

		for (int j = i + 1; j < n - 1; ++j) {
			if (abs(s[i] - s[j]) <= d) {
				++res;
				s.erase(s.begin() + j);
				//s.erase(s.begin() + i);
				//i--;
				break;
			}
		}
	}

	cout << res;

	return 0;

}