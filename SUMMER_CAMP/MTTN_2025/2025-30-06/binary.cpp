// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "binary"
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
    unsigned long long n, k; cin >> n >> k;
    bitset<63> bs(n);
 
    int bits_1 = 0;
    for (unsigned int mask = 0; mask < 64; ++mask) {
        if (bs[mask] == 1) {
            ++bits_1;
            if (bits_1 >= k) {
                cout << n << ln;
                return;
            }
        }
        else bits_1 = 0;
    }
 
    for (unsigned int mask = 0; mask < k; ++mask) {
        bs[mask] = 1;
    }
 
    int idx = k, idx2 = 0;
    while (bs[idx] == 1) {
        bs[idx2] = 0;
        if (bs.to_ullong() < n) {
            bs[idx] = 1;
            break;
        }
        ++idx; ++idx2;
    }
 
    cout << bs.to_ullong() << ln;
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