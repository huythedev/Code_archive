#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll x;
	cin >> x;
	
	if (x % 4096 != 0) {
		cout << (x / 4096 + 1) * 4;
	}
	else {
		cout << (x / 4096) * 4;
	}

    return 0;
}