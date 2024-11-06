#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ln endl;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q; cin >> q;
	while(q--) {
		ll n; cin >> n;

		cout << round(sqrt(n - 1) - 0.5) + 1 << ln;
	}
		
	return 0;	
}
