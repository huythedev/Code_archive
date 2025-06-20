// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "515"
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        
        int l = 0, r = n - 1;
        int mid = n / 2;
        bool found = false;
        while (l < r) {
            // cout << l << ' ' << mid << ' ' << r << ln;
            if (a[mid] == x) {
                cout << mid + 1 << ln;
                found = true;
                break;
            }

            if (x < a[mid]) {
                r = mid - 1;
                mid = (l + r) / 2;
            }
            else {
                l = mid + 1;
                mid = (l + r) / 2;
            }
        }


        if (!found) cout << r + 1 << ln;
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