// Author: huythedev
// Problem Link: https://marisaoj.com/problem/525
#include <bits/stdc++.h>
using namespace std;

#define NAME "525"
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
    int type; cin >> type;

    if (type == 1) {
        int x; cin >> x;
        bs ^= x;
    } else if (type == 2) {
        for (int i = 31; i >= 0; --i) {
            if (bs[i] == 1) {
                bs.flip(i);
                break;
            }
        }
    } else {
        cout << bs.count() << ln;
    }
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