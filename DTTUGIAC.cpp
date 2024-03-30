#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll x, y, u, v;
    cin >> x >> y >> u >> v;
    
    ll n1 = abs(u - x);
    ll n2 = abs(v - y);

	cout << n1 * n2;

    return 0;
}