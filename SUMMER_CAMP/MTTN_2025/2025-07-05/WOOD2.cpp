// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "WOOD2"
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

const int MAXN = 2005;
char grid[MAXN][MAXN];
bool cut_h[MAXN][MAXN];
bool cut_v[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

void compute_large_saw_cuts() {
    for (int k = 0; k < m - 1; k++) {
        vector<int> diff_rows;
        for (int i = 0; i < n; i++) {
            if (grid[i][k] != grid[i][k + 1]) {
                diff_rows.push_back(i);
            }
        }
        if (diff_rows.empty()) continue;
        int start = diff_rows[0];
        if (start == 0) {
            int end = start;
            for (int x = 1; x < diff_rows.size(); x++) {
                if (diff_rows[x] == diff_rows[x-1] + 1) {
                    end = diff_rows[x];
                } else {
                    break;
                }
            }
            for (int i = start; i <= end; i++) {
                cut_v[i][k] = true;
            }
        }
        int last = diff_rows.back();
        if (last == n - 1) {
            int end = last;
            for (int x = diff_rows.size() - 2; x >= 0; x--) {
                if (diff_rows[x] == diff_rows[x+1] - 1) {
                    end = diff_rows[x];
                } else {
                    break;
                }
            }
            for (int i = end; i <= last; i++) {
                cut_v[i][k] = true;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        vector<int> diff_cols;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != grid[i + 1][j]) {
                diff_cols.push_back(j);
            }
        }
        if (diff_cols.empty()) continue;
        int start = diff_cols[0];
        if (start == 0) {
            int end = start;
            for (int x = 1; x < diff_cols.size(); x++) {
                if (diff_cols[x] == diff_cols[x-1] + 1) {
                    end = diff_cols[x];
                } else {
                    break;
                }
            }
            for (int j = start; j <= end; j++) {
                cut_h[i][j] = true;
            }
        }
        int last = diff_cols.back();
        if (last == m - 1) {
            int end = last;
            for (int x = diff_cols.size() - 2; x >= 0; x--) {
                if (diff_cols[x] == diff_cols[x+1] - 1) {
                    end = diff_cols[x];
                } else {
                    break;
                }
            }
            for (int j = end; j <= last; j++) {
                cut_h[i][j] = true;
            }
        }
    }
}

bool is_connected(int i1, int j1, int i2, int j2) {
    if (grid[i1][j1] == grid[i2][j2]) return true;
    if (i1 == i2 && j1 + 1 == j2) return !cut_v[i1][j1];
    if (i1 == i2 && j1 - 1 == j2) return !cut_v[i1][j1-1];
    if (i1 + 1 == i2 && j1 == j2) return !cut_h[i1][j1];
    if (i1 - 1 == i2 && j1 == j2) return !cut_h[i1-1][j1];
    return false;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && is_connected(i, j, ni, nj)) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int count_components() {
    memset(visited, 0, sizeof(visited));
    int components = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                components++;
            }
        }
    }
    return components;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(cut_h, 0, sizeof(cut_h));
    memset(cut_v, 0, sizeof(cut_v));
    compute_large_saw_cuts();
    int result = count_components();

    cout << result << ln;
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
