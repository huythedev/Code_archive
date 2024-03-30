#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll N;
	cin >> N;
	
	ll res = 0;
	while(N--) {
		ll tmp;
		cin >> tmp;
		if (tmp % 2 == 0) {
			res += tmp;
		}
	}
	
	cout << res;
    return 0;
}