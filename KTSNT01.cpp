#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checknto(ll n)
{
    if (n == 2 || n == 3) {
        return true;
    }
    
    if (n < 3 || n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	if(checknto(n)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

    return 0;
}