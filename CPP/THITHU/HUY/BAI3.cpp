#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI3"

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

int main() {
	fastio();
	docfile();

	int n, k; cin >> n >> k;

	unordered_map<int, int> freq;
	int t, res = 0;
	while(cin >> t) {
		freq[t]++;
		res += freq[k - t] * freq[t];
	}

	cout << res;

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}

