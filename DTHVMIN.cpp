#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	
	ll m = min(a1, b1), n = max(a1, b1), o = min(a2, b2), p = max(a2, b2);
	
	if(m == o && n == p) {
		cout << (m + o) * (m + o);
	}
	else if(m + o >= max(n, p)) {
		cout << (m + o) * (m + o);
	}
	else if(m + o < max(n, p)) {
		cout << max(n, p) * max(n, p);
	}

    return 0;
}
