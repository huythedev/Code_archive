// Author: huythedev
// Problem Link: https://marisaoj.com/problem/586
#include <bits/stdc++.h>
using namespace std;

#define NAME "586"
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
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> B(x, vector<int>(m));
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> B[i][j];
        }
    }

    for (int Arow = 0; Arow < (n - x + 1); ++Arow) {
        for (int Acol = 0; Acol < (m - y + 1); ++Acol) {
            bool exist = true;

            for (int Brow = 0; Brow < x; ++Brow) {
                for (int Bcol = 0; Bcol < y; ++Bcol) {
                    if (A[Arow + Brow][Acol + Bcol] != B[Brow][Bcol]) {
                        exist = false;
                        break;
                    }
                }
                if (!exist) break;
            }

            if (exist) {
                cout << "YES" << ln;
                return;
            }
        }
    }

    cout << "NO" << ln;
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