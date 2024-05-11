#include <bits/stdc++.h>
using namespace std;

#define NAME "ict24revpair"
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

	int N; cin >> N;

	map<int, int> freq;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		freq[a]++;
	}

	int res = 0;
	map<int, int> freq1;
	for (auto &kv : freq) {
		int t = kv.first;
		string tmp;
		tmp += to_string(t);
		reverse(tmp.begin(), tmp.end());
		t = stoi(tmp);

		if (freq1[kv.first] == 0 && freq1[t] == 0) {
			res += kv.second * freq[t];
			freq1[kv.first]++;
		}
	}

	cout << res;

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

	return 0;
}