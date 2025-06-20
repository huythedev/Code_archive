// Author: huythedev
// Problem Link: https://marisaoj.com/problem/38
#include <bits/stdc++.h>
using namespace std;

#define NAME "38"
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
    int n, m; cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> table[i][j];
    }

    for (int col = 0; col < m; ++col) {
        int sum = 0;
        for (int row = 0; row < n; ++row) {
            // cout << table[row][col] << ' ' << row << ' ' << col << ln;
            sum += table[row][col];
        }

        cout << sum << ' ';

        // cout << "-----" << ln;
    }

    cout << ln;
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