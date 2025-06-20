// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "407"
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
    vector<vector<int>> matrix(n, vector<int>(m));

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i)
            matrix[top][i] = num++;
        top++;

        for (int i = top; i <= bottom; ++i)
            matrix[i][right] = num++;
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = num++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = num++;
            left++;
        }
    }

    for (auto vec : matrix) {
        for (auto i : vec) cout << i << ' ';
        cout << ln;
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