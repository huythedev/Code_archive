// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    ll res = 0;
    for (int i = 2; i < n; i++) {
        ll b;
        if (i == n - 1) 
            b = a[n - 1];
        else 
            b = max(a[i], a[n - 1] - a[i]);
        
        ll cnt = 0;
        for (int j = 1; j < i; j++) {
            ll val = b - a[j] + 1;
            auto it = lower_bound(a.begin(), a.begin() + j, val);
            int tmp = it - a.begin();
            if (tmp < j) 
                cnt += j - tmp;
        }
        res += cnt;
    }
    
    cout << res << ln;
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