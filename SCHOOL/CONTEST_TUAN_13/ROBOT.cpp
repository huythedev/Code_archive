#include <bits/stdc++.h>
using namespace std;

#define NAME "ROBOT"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int m, n, k;
vector<vector<int>> table;
vector<vector<int>> prefix;
vector<vector<int>> visited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y, int component_id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = component_id;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (isValid(nx, ny) && table[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = component_id;
                q.push({nx, ny});
            }
        }
    }
}

bool isValidArea(int r, int c) {
    int r2 = r + k - 1;
    int c2 = c + k - 1;
    if (r2 >= m || c2 >= n) return false;
    int top_left = (r > 0 && c > 0) ? prefix[r][c] : 0;
    int top_right = (r > 0) ? prefix[r][c2 + 1] : 0;
    int bottom_left = (c > 0) ? prefix[r2 + 1][c] : 0;
    int bottom_right = prefix[r2 + 1][c2 + 1];
    int ones = bottom_right - top_right - bottom_left + top_left;
    return ones == 0;
}

signed main() {
    fastio();
    docfile();

    cin >> m >> n >> k;
    table.assign(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> table[i][j];
        }
    }

    prefix.assign(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - 
                                   prefix[i][j] + table[i][j];
        }
    }

    visited.assign(m, vector<int>(n, 0));
    int component_id = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j] == 0 && !visited[i][j]) {
                bfs(i, j, component_id);
                ++component_id;
            }
        }
    }

    set<int> components_with_valid_areas;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isValidArea(i, j)) {
                components_with_valid_areas.insert(visited[i][j]);
            }
        }
    }

    cout << (components_with_valid_areas.empty() ? 0 : components_with_valid_areas.size()) << endl;
    
    time();
    return 0;
}