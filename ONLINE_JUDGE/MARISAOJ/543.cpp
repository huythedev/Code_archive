// Author: huythedev
// Problem Link: https://marisaoj.com/problem/543
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

void genBinaryLenN(int len, string bin) {
    if (bin.sz == len) {
        cout << bin << ln;
        return;
    }

    genBinaryLenN(len, bin + '0');
    genBinaryLenN(len, bin + '1');
}

void solve() {
    int n; cin >> n;
    genBinaryLenN(n, "");
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