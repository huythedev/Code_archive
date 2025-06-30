// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "greedy-is-wrong"
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

bool isBeauty(const vector<string>& grid) {
    int n = grid.size();
    
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (grid[j][i] == grid[j - 1][i]) {
                cnt++;
                if (cnt >= n / 2 + 1) {
                    return false;
                }
            } 
            else {
                cnt = 1;
            }
        }
    }
    return true;
}

void changeColor(vector<string>& grid, int row, char target) {
    for (int j = 0; j < grid[0].sz; j++) {
        grid[row][j] = target;
    }
}

void solve() {
    int n; 
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    if (isBeauty(grid)) {
        cout << 0 << ln;
        return;
    }

    for (int row = 0; row < n; row++) {
        vector<string> grid2 = grid;
        changeColor(grid2, row, 'W');
        if (isBeauty(grid2)) {
            cout << 1 << ln;
            return;
        }
        
        grid2 = grid;
        changeColor(grid2, row, 'B');
        if (isBeauty(grid2)) {
            cout << 1 << ln;
            return;
        }
    }

    cout << 2 << ln;
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