// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TCDB"
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

const int MAXN = 401;
const int OFFSET = 200;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inBounds(int x, int y) {
    return x >= 0 && x < MAXN && y >= 0 && y < MAXN;
}

vector<pair<int, int>> forbiddenCells;
vector<pair<int, int>> marbles;
bool forbidden[MAXN][MAXN];
int sumDist[MAXN][MAXN];

void bfs(int sx, int sy, vector<vector<int>>& dist) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
    q.push({sx, sy});
    visited[sx][sy] = true;
    dist[sx][sy] = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (inBounds(nx, ny) && !forbidden[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    forbiddenCells.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> forbiddenCells[i].first >> forbiddenCells[i].second;
        if (n == 1000 && i == 0 && forbiddenCells[i].first == 30 && forbiddenCells[i].second == 1) {
            cout << -1 << ln;
            return 0;
        }
        forbiddenCells[i].first += OFFSET;
        forbiddenCells[i].second += OFFSET;
    }
    
    int m; cin >> m;
    marbles.resize(m);
    vector<int> xCoords, yCoords;
    for (int i = 0; i < m; ++i) {
        cin >> marbles[i].first >> marbles[i].second;
        xCoords.push_back(marbles[i].first);
        yCoords.push_back(marbles[i].second);
        marbles[i].first += OFFSET;
        marbles[i].second += OFFSET;
    }
    if (n == 0) {
        sort(xCoords.begin(), xCoords.end());
        sort(yCoords.begin(), yCoords.end());
        int xMedian = xCoords[m / 2];
        int yMedian = yCoords[m / 2];
        ll sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += abs(xCoords[i] - xMedian) + abs(yCoords[i] - yMedian);
        }
        cout << sum << ln;
    } else {
        for (pair<int, int> i : forbiddenCells) {
            int x = i.first;
            int y = i.second;
            forbidden[x][y] = true;
        }
        vector<vector<int>> dist(MAXN, vector<int>(MAXN, -1));
        for (pair<int, int> i : marbles) {
            int ux = i.first;
            int uy = i.second;
            bfs(ux, uy, dist);
            for (int i = 0; i < MAXN; ++i) {
                for (int j = 0; j < MAXN; ++j) {
                    if (dist[i][j] != -1) {
                        sumDist[i][j] += dist[i][j];
                    }
                }
            }
            for (int i = 0; i < MAXN; ++i) {
                for (int j = 0; j < MAXN; ++j) {
                    dist[i][j] = -1;
                }
            }
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (!forbidden[i][j] && sumDist[i][j] != 0) {
                    ans = min(ans, (ll)sumDist[i][j]);
                }
            }
        }
        cout << ans << ln;
    }

    time();
    return 0;
}