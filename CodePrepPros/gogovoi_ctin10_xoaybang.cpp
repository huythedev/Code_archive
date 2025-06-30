// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin10_xoaybang"
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

vector<vector<int>> rotate(vector<vector<int>> matrix, int to_rotate) {
    int n = matrix.size();
    to_rotate = (to_rotate % 4 + 4);
    while (to_rotate--) {
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = rotated;
    }
    return matrix;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int to_rotate = 0;
    while (q--) {
        int type; cin >> type;
        if (type == 1)
            ++to_rotate;
        else 
            --to_rotate;
    }

    to_rotate %= 4;
    if (to_rotate != 0) 
        matrix = rotate(matrix, to_rotate);
    
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