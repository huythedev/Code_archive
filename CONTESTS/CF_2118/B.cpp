// Author: huythedev
// Problem Link: https://codeforces.com/contest/2118/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    int n;
    cin >> n;

    vector<tuple<int, int, int>> ops;
    for (int i = 1; i <= n; ++i) {
        ops.emplace_back(i, 1, n - i + 1);
        if (n - i + 2 <= n)
            ops.emplace_back(i, n - i + 2, n);
    }
    
    cout << ops.size() << ln;
    for (const auto& op : ops) {
        cout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << ln;
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