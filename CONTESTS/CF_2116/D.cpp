// Author: huythedev
// Problem Link: https://codeforces.com/contest/2116/problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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
    int n, q;
    cin >> n >> q;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<tuple<int, int, int>> ops(q);
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ops[i] = make_tuple(x - 1, y - 1, z - 1);
    }

    vector<bool> vec(n, false);
    for (auto [x, y, z] : ops) {
        vec[z] = true;
    }

    vector<ll> req(n, 0);
    for (int i = q - 1; i >= 0; i--) {
        auto [x, y, z] = ops[i];
        req[x] = max(req[x], b[z]);
        req[y] = max(req[y], b[z]);
    }

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        if (!vec[i]) {
            a[i] = b[i];
        } else {
            a[i] = req[i];
        }
    }

    vector<ll> c = a;
    for (auto [x, y, z] : ops) {
        c[z] = min(c[x], c[y]);
    }
    if (c == b) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << ln;
    } else {
        cout << "-1" << ln;
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