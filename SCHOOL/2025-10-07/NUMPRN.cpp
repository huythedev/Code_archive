// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NUMPRN"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void solve() {
    ll n;
    cin >> n;

    set<ll> prn_numbers;
    const int lim = 1000000;
    
    for (ll x = 1; x <= lim + 1; ++x) {
        if (n % x == 0) {
            if (n % (x + 1) == 0) {
                prn_numbers.insert(x);
            }
        }
    }

    for (ll k = 1; k <= lim; ++k) {
        if (n % k == 0) {
            ll m = n / k;
            
            ll delta = 1 + 4 * m;
            if (delta >= 0) {
                ll s = round(sqrt((ld)delta));
                
                if (s * s == delta) {
                    if ((s - 1) > 0 && (s - 1) % 2 == 0) {
                        ll x = (s - 1) / 2;
                        prn_numbers.insert(x);
                    }
                }
            }
        }
    }

    if (prn_numbers.empty()) {
        cout << -1 << ln;
    } 
    else {
        for (ll prn : prn_numbers)
            cout << prn << ' ';
        cout << ln;
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}