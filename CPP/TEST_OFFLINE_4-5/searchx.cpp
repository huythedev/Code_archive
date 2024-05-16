#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q; cin >> n >> q;

	map<int, int> freq;
	while(n--) {
		int t; cin >> t;
		freq[t]++;
	}
	while(q--) {
		int t; cin >> t;
		if(freq[t] != 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
