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
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int curr = h[k];
    sort(h.begin(), h.end());

    int tmp = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (curr >= h[i]) {
            continue;
        }

        tmp += h[i] - curr;
        if (tmp - 1 >= curr) {
            ok = false;
            break;
        }

        curr = h[i];
    }
    
    cout << (ok ? "YES" : "NO") << ln;
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