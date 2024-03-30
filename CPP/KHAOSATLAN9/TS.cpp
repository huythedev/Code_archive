#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	
	if (n > m) {
		cout << n + m << " " << n - m;
	}
	else {
		cout << m - n << " " << n + m;
	}

    return 0;
}