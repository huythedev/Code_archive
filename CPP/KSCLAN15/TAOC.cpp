#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	if (k + (min (m, n)) > max(m, n)) {
		cout << "0";
		return 0;
	}
	else {
		cout << max(m, n) - (k + (min(m, n)));
	}

    return 0;
}