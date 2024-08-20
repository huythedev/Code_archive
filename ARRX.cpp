#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, x;
	cin >> n >> x;
	ll t;
	ll res = 0;
	while(cin >> t) {
		if(t == x) {
			++res;
		}
	}
	cout << res;

    return 0;
}