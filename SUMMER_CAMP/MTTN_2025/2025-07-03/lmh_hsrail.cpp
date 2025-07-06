// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_hsrail"
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
    vector<int> h2(n);
    for (int i = 0; i < n; ++i) {
        cin >> h2[i];
    }

    vector<int> h = h2;
    
    for (int i = 1; i < n; ++i) {
        h[i] = max(h[i - 1] - 1, h[i]);
    }

    h.push_back(h[n - 1]);
    for (int i = n - 1; i >= 0; --i) {
        h[i] = max(h[i], h[i + 1] - 1);
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += abs(h[i] - h2[i]);
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
