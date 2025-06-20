// Author: huythedev
// Problem Link: https://codeforces.com/contest/2111/problem/C
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    ll min_cost = 1e18;
    int l = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (i == n || a[i] != a[i - 1]) {
            int r = i - 1;
            ll v = a[l];
            ll cost = (ll)l * v + (ll)(n - 1 - r) * v;
            min_cost = min(min_cost, cost);
            l = i;
        }
    }
    
    cout << min_cost << ln;
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