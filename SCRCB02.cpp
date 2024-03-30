#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll a, b;
	cin >> a >> b;
	
	ll res = 0;
	
	ll tmp = a;
	while(tmp % 3 != 0) {
		++tmp;
	}
	
	while(tmp <= b) {
		tmp += 3;
		++res;
	}
	
	cout << res;

    return 0;
}