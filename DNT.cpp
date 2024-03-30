#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPrime(ll n) {
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll N;
	cin >> N;
	
	ll tongsnt = 0, sosnt = 0;
	ll t;
	while(cin >> t) {
		if(isPrime(t)) {
			sosnt++;
			tongsnt += t;
		}
	}
	
	cout << "So luong so nguyen to: " << sosnt << endl;
	cout << "Tong cua chung la: " << tongsnt;
	
	return 0;
}