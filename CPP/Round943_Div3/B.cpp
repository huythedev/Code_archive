#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int solve(string a, string b) {
	map<char, int> cnt;

	for (char c : b)
		cnt[c]++;

	int k = 0;

	for (char c : a) {
		if (cnt.find(c) != cnt.end() && cnt[c] > 0) {
			k++;
			cnt[c]--;
		}
		else
			break;
	}

	return k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		string a, b; cin >> a >> b;

		cout << solve(a, b) << ln;
	}

	return 0;
}