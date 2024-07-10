#include <bits/stdc++.h>
using namespace std;

#define NAME "DANVU"

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
	fastio(); docfile();

	int n, m; cin >> n >> m;

	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0, j = 0;
	for(int i = 0; i < n && j < m; ++i) {
		if(a[i] > b[j]) {
			++res;
			++j;
		}		
	}

	cout << res;
	return 0;
}
