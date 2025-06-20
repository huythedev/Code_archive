// Author: huythedev
// Problem Link: https://marisaoj.com/problem/528
#include <bits/stdc++.h>
using namespace std;

#define NAME "528"
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
    vector<int> A(n);
    for (int &x : A) cin >> x;

    vector<pair<int, int>> ops(q);
    for (int i = 0; i < q; ++i) {
        cin >> ops[i].first >> ops[i].second;
    }

    for (int i = q - 1; i >= 0; --i) {
        int x = ops[i].first, y = ops[i].second;
        x--; y--;
        swap(A[x], A[y]);
    }

    for (int x : A) cout << x << ' ';
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