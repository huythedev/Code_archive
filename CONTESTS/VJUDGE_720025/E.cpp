// Author: huythedev
// Problem Link: https://vjudge.net/contest/720025#problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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
    int n; cin >> n;
    vector<vector<int>> positions(n + 1);
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        positions[val].push_back(i);
    }

    int queries; cin >> queries;
    while (queries--) {
        int l, r, val; cin >> l >> r >> val;
        l--; r--;

        const auto& idx = positions[val];

        auto it_l = lower_bound(idx.begin(), idx.end(), l);
        auto it_r = upper_bound(idx.begin(), idx.end(), r);

        cout << distance(it_l, it_r) << ln;
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