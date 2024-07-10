#include <bits/stdc++.h>
using namespace std;

#define NAME "SX"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	docfile();
	
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	
	
	return 0;
}
