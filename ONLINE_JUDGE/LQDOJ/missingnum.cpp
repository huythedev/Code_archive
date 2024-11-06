#include <bits/stdc++.h>
using namespace std;

#define NAME "missingnum"
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

	int n, m; cin >> n >> m;
	vector<int> c(n);
	map<int, int> freq_c;
	for (int &i : c) {
		cin >> i;
		freq_c[i]++;
	}
	map<int, int> freq;
	int t;
	while (cin >> t)
		freq[t]++;

	for (auto &kv : freq_c)
		kv.second -= freq[kv.first];

	for (auto &kv : freq_c) {
		for (int i = 0; i < kv.second; ++i)
			cout << kv.first << ' ';
	}

	return 0;
}