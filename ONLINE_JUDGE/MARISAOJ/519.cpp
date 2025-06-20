// Author: huythedev
// Problem Link: https://marisaoj.com/problem/519
#include <bits/stdc++.h>
using namespace std;

#define NAME "519"
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

bitset<32> bs(0);

void solve() {
    int type, k; cin >> type >> k;
    
    if (type == 1) {
        bs[k] = 1;
    } else if (type == 2) {
        bs[k] = 0;
    } else {
        bs[k] = ~bs[k];
    }

    cout << bs.to_ulong() << ln;
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