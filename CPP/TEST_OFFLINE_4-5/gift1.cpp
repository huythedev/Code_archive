#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	map<ll, int> freq;
	while(n--) {
		ll t; cin >> t;
		freq[t]++;
	}

	cout << freq.size();
	



	return 0;	
}
