#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

const int MAXR = 100;
const int MAXC = 100;
const int MAXN = 15;
const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int R, C, N;
char grid[MAXR][MAXC];
pair<int, int> shrines[MAXN];
int dist[MAXR][MAXC][1 << MAXN];

inline bool isValid(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != '#';
}

int bfs() {
    memset(dist, 0x3f, sizeof(dist));
    
    int initialMask = 0;
    for (int i = 0; i < N; ++i) {
        if (shrines[i].first == 0 && shrines[i].second == 0) {
            initialMask |= (1 << i);
        }
    }
    
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, initialMask);
    dist[0][0][initialMask] = 0;
    
    while (!q.empty()) {
        auto [x, y, mask] = q.front();
        q.pop();
        
        if (mask == (1 << N) - 1) {
            return dist[x][y][mask];
        }
        
        for (int dir = 0; dir < 4; ++dir) {
            int newX = x + dx[dir];
            int newY = y + dy[dir];
            
            if (!isValid(newX, newY)) continue;
            
            int newMask = mask;
            for (int i = 0; i < N; ++i) {
                if (newX == shrines[i].first && newY == shrines[i].second) {
                    newMask |= (1 << i);
                    break;
                }
            }
            
            if (dist[newX][newY][newMask] > dist[x][y][mask] + 1) {
                dist[newX][newY][newMask] = dist[x][y][mask] + 1;
                q.emplace(newX, newY, newMask);
            }
        }
    }
    
    return -1;
}

int main() {
    fastio();
    docfile();
    
    cin >> R >> C >> N;
    
    int shrineCount = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                shrines[shrineCount++] = {i, j};
            }
        }
    }
    
    cout << bfs();
    
    time();
    return 0;
}