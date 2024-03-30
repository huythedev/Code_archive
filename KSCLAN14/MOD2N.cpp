#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	
	cout << m % (ll)pow(2, n);

    return 0;
}