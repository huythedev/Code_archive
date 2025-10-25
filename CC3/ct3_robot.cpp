// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
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
    int n, m, k; cin >> n >> m >> k;

    vector<string> vec(n);
    int Rstart = -1, Cstart = -1, Rend = -1, Cend = -1;

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        for (int j = 0; j < m; ++j) {
            if (vec[i][j] == 'S') Rstart = i, Cstart = j;
            else if (vec[i][j] == 'F') Rend = i, Cend = j;
        }
    }

    const int INF = 1e9;
    static int dist[1000][1000][31];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int t = 0; t <= k; ++t)
                dist[i][j][t] = INF;

    deque<tuple<int, int, int>> dq;
    dist[Rstart][Cstart][0] = 0;
    dq.emplace_back(Rstart, Cstart, 0);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!dq.empty()) {
        auto [r, c, cool] = dq.front();
        dq.pop_front();

        int cur = dist[r][c][cool];
        if (r == Rend && c == Cend) {
            cout << cur << ln;
            return;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vec[nr][nc] == '#') 
                continue;

            int moveCost = (cool > 0 ? 1 : 2);
            int nCool = (vec[nr][nc] == 'C' ? k : max(0, cool - 1));
            int newTime = cur + moveCost;

            if (newTime < dist[nr][nc][nCool]) {
                dist[nr][nc][nCool] = newTime;
                if (moveCost == 1) 
                    dq.emplace_front(nr, nc, nCool);
                else 
                    dq.emplace_back(nr, nc, nCool);
            }
        }
    }

    cout << -1 << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}