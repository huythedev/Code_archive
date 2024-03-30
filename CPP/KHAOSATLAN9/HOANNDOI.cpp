#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	
	if (a > b) {
		cout << a * 2 << " " << b * 2;
	}
	else {
		cout << b << " " << a;
	}
	
    return 0;
}