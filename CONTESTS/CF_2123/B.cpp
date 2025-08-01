// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    int n, j, k;
    cin >> n >> j >> k;
    --j;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (k >= 2) {
        cout << "YES" << ln;
        continue;
    }

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[j]) {
            ok = true;
            break;
        }
    }

    if (ok) {
        cout << "NO" << ln;
    } 
    else {
        cout << "YES" << ln;
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