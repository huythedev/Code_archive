#include <bits/stdc++.h>
using namespace std;

#define NAME "22dnaa2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const string st = "HOITHITINHOCTRECAPTHANHPHO";
const int maxn = 1e7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	string s = "";
	while (s.size() < 1e7)
		s += st;

	int n; cin >> n;
	char c; cin >> c;

	//n--;
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == c)
			++res;

	cout << res;

	return 0;
}