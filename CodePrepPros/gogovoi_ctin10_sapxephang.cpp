// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin10_sapxephang"
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

void print_table(vector<vector<int>> &vec) {
    for (vector<int> i : vec) {
        for (int x : i) cout << x << ' ';
        cout << ln;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    }

    for (int i = 0; i < n; ++i) {
        vector<int> tmp(m);
        for (int j = 0; j < m; ++j)
            tmp[j] = matrix[i][j];
        
        sort(tmp.begin(), tmp.end());

        for (int j = 0; j < m; ++j)
            matrix[i][j] = tmp[j];
    }

    print_table(matrix);
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