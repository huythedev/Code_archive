#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	n = 2 * n - 1;
	
	ll res = 0;
	if((ll)(n / 2 + 1) % 2 == 0) {
		res += (n / 2 + 1) / 2 * (n + 1);
	}
	else {
		res += (n / 2 + 1) / 2 * (n + 1) + n / 2 + 1;
	}
	
	cout << res;

    return 0;
}