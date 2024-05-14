#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b; cin >> a >> b;

	cout << ((b - a + 1) * (a + b)) / 2 << ln << (b - 1) / a;
	
	return 0;
}
