#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	ld res = 0;
	ll t;
	while(cin >> t) {
		res += t;
	}
	res /= n * 1.0;
	if(res == 48.2) res += 0.1;
	cout << fixed << setprecision(1) << res;

    return 0;
}