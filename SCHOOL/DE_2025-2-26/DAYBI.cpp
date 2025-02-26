// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "DAYBI"
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
        auto [cx, cy] = q.front();
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

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    forbiddenCells.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> forbiddenCells[i].first >> forbiddenCells[i].second;
        forbiddenCells[i].first += OFFSET;
        forbiddenCells[i].second += OFFSET;
    }
    int m;
    cin >> m;
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
    } 
    else {
        for (auto [x, y] : forbiddenCells) {
            forbidden[x][y] = true;
        }
        
        vector<vector<bool>> reachable(MAXN, vector<bool>(MAXN, true));
        vector<vector<int>> dist(MAXN, vector<int>(MAXN, -1));
        
        for (auto [ux, uy] : marbles) {
            bfs(ux, uy, dist);
            for (int i = 0; i < MAXN; ++i) {
                for (int j = 0; j < MAXN; ++j) {
                    if (dist[i][j] != -1) {
                        sumDist[i][j] += dist[i][j];
                    } 
                    else if (!forbidden[i][j]) {
                        reachable[i][j] = false;
                    }
                }
            }
            for (int i = 0; i < MAXN; ++i) {
                for (int j = 0; j < MAXN; ++j) {
                    dist[i][j] = -1;
                }
            }
        }
        
        ll minSum = LLONG_MAX;
        bool hasValidPoint = false;
        
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (!forbidden[i][j] && reachable[i][j] && sumDist[i][j] > 0) {
                    minSum = min(minSum, (ll)sumDist[i][j]);
                    hasValidPoint = true;
                }
            }
        }
        
        if (hasValidPoint) {
            cout << minSum << ln;
        } 
        else {
            cout << -1 << ln;
        }
    }

    time();
    return 0;
}