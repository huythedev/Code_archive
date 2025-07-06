// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_islands"
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

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};

void solve() {
    int m, n; cin >> m >> n;
    if (m == 0 || n == 0) {
        cout << 0 << ln;
        return;
    }

    vector<tuple<int, int, int>> grid;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int h;
            cin >> h;
            grid.emplace_back(h, i, j);
        }
    }

    sort(grid.rbegin(), grid.rend());

    DSU dsu(m * n);
    vector<vector<bool>> isLand(m, vector<bool>(n, false));
    int res = 0, curr = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < (int)grid.size(); ) {
        int j = i;
        while (j < (int)grid.size() && get<0>(grid[j]) == get<0>(grid[i]))
            j++;
        
        for (int k = i; k < j; ++k) {
            auto [h, r, c] = grid[k];
            isLand[r][c] = true;
            curr++;
        }

        for (int k = i; k < j; ++k) {
            auto [h, r, c] = grid[k];
            for (int move = 0; move < 4; ++move) {
                int nr = r + dr[move];
                int nc = c + dc[move];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && isLand[nr][nc]) {
                    int u = r * n + c;
                    int v = nr * n + nc;
                    if (dsu.find(u) != dsu.find(v)) {
                        dsu.unite(u, v);
                        curr--;
                    }
                }
            }
        }
        
        res = max(res, curr);
        i = j;
    }
    
    cout << res << ln;
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