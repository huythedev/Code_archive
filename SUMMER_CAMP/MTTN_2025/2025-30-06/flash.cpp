// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "flash"
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

int m, n, k;
vector<string> grid;

int bfs(int xs, int ys, int xt, int yt) {
    xs--; ys--; xt--; yt--;
    if (xs == xt && ys == yt) return 0;

    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    
    dist[xs][ys] = 0;
    q.push({xs, ys});

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int d = dist[r][c];

        for (int i = 1; i <= k; ++i) {
            int nc = c + i;
            if (nc >= n || grid[r][nc] == '#') break;
            if (dist[r][nc] != -1 && dist[r][nc] <= d) break;
            
            if (dist[r][nc] == -1) {
                dist[r][nc] = d + 1;
                if (r == xt && nc == yt) return d + 1;
                q.push({r, nc});
            }
        }

        for (int i = 1; i <= k; ++i) {
            int nc = c - i;
            if (nc < 0 || grid[r][nc] == '#') break;
            if (dist[r][nc] != -1 && dist[r][nc] <= d) break;
            if (dist[r][nc] == -1) {
                dist[r][nc] = d + 1;
                if (r == xt && nc == yt) return d + 1;
                q.push({r, nc});
            }
        }

        for (int i = 1; i <= k; ++i) {
            int nr = r + i;
            if (nr >= m || grid[nr][c] == '#') break;
            if (dist[nr][c] != -1 && dist[nr][c] <= d) break;
            if (dist[nr][c] == -1) {
                dist[nr][c] = d + 1;
                if (nr == xt && c == yt) return d + 1;
                q.push({nr, c});
            }
        }

        for (int i = 1; i <= k; ++i) {
            int nr = r - i;
            if (nr < 0 || grid[nr][c] == '#') break;
            if (dist[nr][c] != -1 && dist[nr][c] <= d) break;
            if (dist[nr][c] == -1) {
                dist[nr][c] = d + 1;
                if (nr == xt && c == yt) return d + 1;
                q.push({nr, c});
            }
        }
    }

    return dist[xt][yt];
}

void solve() {
    cin >> m >> n >> k;
    grid.resize(m);
    for (int i = 0; i < m; i++) 
        cin >> grid[i];
    int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;

    cout << bfs(xs, ys, xt, yt) << ln;
}

signed main() {
    fastio();
    docfile();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}