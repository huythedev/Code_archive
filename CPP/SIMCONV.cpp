#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cen_to_sec(ll n) {
	return n * 100 * 365 * 24 * 60 * 60;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;
	
	ll tmp;
	while(cin >> tmp) {
		cout << cen_to_sec(tmp) << endl;
	}

    return 0;
}