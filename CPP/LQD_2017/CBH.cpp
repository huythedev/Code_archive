#include <bits/stdc++.h>
using namespace std;

#define NAME "CBH"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    ll x; cin >> x;

    for(ll i = 1; i * i <= x; ++i) {
        if(x % i == 0) {
            ll tmp = x / i;
            if(tmp == (ll)sqrt(tmp) * (ll)sqrt(tmp)) {
                cout << sqrt(tmp);
                return 0;
            }
        }
    }

    cout << 1;

    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}
