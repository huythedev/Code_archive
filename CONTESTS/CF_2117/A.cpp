// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i]; 
    
    int i_min = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            i_min = i + 1;
            break;
        }
    }

    int i_max = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            i_max = i + 1;
            break;
        }
    }

    int required_x = i_max - (i_min - 1);
    
    if (x >= required_x) cout << "YES" << ln;
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