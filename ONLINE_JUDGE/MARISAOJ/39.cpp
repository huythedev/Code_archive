// Author: huythedev
// Problem Link: https://marisaoj.com/problem/39
#include <bits/stdc++.h>
using namespace std;

#define NAME "39"
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
    int n, m, x, y; cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> table[i][j];
    }

    int sum = 0;
    // Upper left direction
    // col - 1, row - 1
    for (int row = x - 1, col = y - 1; row >= 0 && col >= 0; --row, --col) {
        sum += table[row][col];
        // cout << table[row][col] << ' ';
    }
    // cout << ln;
    // Upper right direction
    // col + 1, row - 1
    for (int row = x - 1, col = y + 1; row >= 0 && col < m; --row, ++col) {
        sum += table[row][col];
        // cout << table[row][col] << ' ';
    }
    // cout << ln;
    // Lower left direction
    // col - 1, row + 1
    for (int row = x + 1, col = y - 1; row < n && col >= 0; ++row, --col) {
        sum += table[row][col];
        // cout << table[row][col] << ' ';
    }
    // cout << ln;
    // Lower right direction
    // col + 1, row + 1
    for (int row = x + 1, col = y + 1; row < n && col < m; ++row, ++col) {
        sum += table[row][col];
        // cout << table[row][col] << ' ';
    }
    // cout << ln;

    cout << sum + table[x][y] << ln;
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