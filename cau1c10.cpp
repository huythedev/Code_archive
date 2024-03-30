#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;

    ld tbc = 0;
    ll snt = 0;
    bool ddt = true;

    ll tmp = -100000000;

    ll t;
    while(cin >> t) {
        tbc += t;
        if(isPrime(t)) {
            ++snt;
        }

        if(tmp == -100000000) {
            tmp = t;
        }
        else {
            if(t != tmp + 1) {
                ddt = false;
            }
        }
    }

	tbc /= N;
	tbc = tbc * 1000;
	ll tmp1 = (ll)tbc;
	if(tmp1 % 10 < 5) {
		tmp1 /= 10;
		tbc = tmp1 / 100.0;
	}
	else {
		tmp1 /= 10;
		++tmp1;
		tbc = tmp1 / 100.0;
	}
	
    cout << fixed << setprecision(2) << tbc << ln 
         << snt << ln;
    if(ddt) {
        cout << "Day A la day don dieu tang";
    }
    else {
        cout << "Day A khong la day don dieu tang";
    }

    return 0;
}