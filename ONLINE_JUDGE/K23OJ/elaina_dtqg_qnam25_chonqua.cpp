// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CHONQUA"
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

bool satisfied(int x, int y, int z) {
    return y - x <= z - y && x < y && y < z;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        int ans = -1;
        for (int x = l; x <= r - 2; ++x) {
            for (int y = x + 1; y <= r - 1; ++y) {
                for (int z = y + 1; z <= r; ++z) {
                    if (satisfied(x, y, z)) ans = max(ans, a[x] + a[y] + a[z]);
                }
            }
        }

        cout << ans << ln;
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