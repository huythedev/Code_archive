// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int val; cin >> val;
            auto it = lower_bound(a.begin(), a.end(), val);
            a.insert(it, val);
        }
        else if (type == 2) {
            int k; cin >> k;
            cout << a[k - 1] << ln;
        }
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}