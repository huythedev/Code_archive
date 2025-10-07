// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll cost = 0, curr = 0, tmp = 0;
    for (ll i = 1; i <= n; i++) {
        ll delta;
        if (i % 2 == 1)
            delta = 0 - a[i - 1];
        else
            delta = a[i - 1];
        
        ll prev = curr;
        curr += delta;

        if (i >= 2) {
            if (curr < tmp) {
                ll diff = tmp - curr;
                cost += diff;
                
                if (i % 2 == 1) {
                    curr += diff;
                } 
                else {
                    prev += diff;
                    curr += diff;
                }
            }
        }

        tmp = max(tmp, prev);
    }
    
    cout << cost << ln;
}

signed main() {
    fastIO();
    fileIO();

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}