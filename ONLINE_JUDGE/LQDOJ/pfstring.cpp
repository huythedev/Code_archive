#include <bits/stdc++.h>
using namespace std;

#define NAME "pfstring"
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

	ll n; cin >> n;
	cin >> ws;
	string st; getline(cin, st);

	int freq[26] = {0};
	for (char c : st)
		freq[c - 'a']++;

	ll res = 0;
	for (ll i = 0; i < 26; ++i)
		if (freq[i] > 1)
			res += freq[i] * (freq[i] - 1) / 2;

	cout << res;

	return 0;
}