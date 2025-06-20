// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
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
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    ll d = a[1] - a[0];
    bool ok = true;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i + 1] - a[i] != d) {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "NO" << ln;
        return;
    }
    
    ll tmp = a[0] - d;
    if (tmp < 0 || tmp % (n + 1) != 0) {
        cout << "NO" << ln;
        return;
    }
    
    ll q = tmp / (n + 1);
    ll p = a[0] - (ll)n * q;
    
    if (p >= 0) cout << "YES" << ln;
    else cout << "NO" << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}