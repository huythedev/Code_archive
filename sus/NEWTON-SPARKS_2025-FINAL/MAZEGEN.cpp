// Author: huythedev
// Problem Link: 
// caluht
#include <bits/stdc++.h>
using namespace std;

#define NAME "MAZEGEN"
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

int m, n;
vector<string> maze;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs() {
    if (maze[0][0] == '#' || maze[m - 1][n - 1] == '#') {
        return -1;
    }

    vector<vector<int>> dist(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    dist[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == m - 1 && c == n - 1) {
            return dist[r][c];
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return -1;
}

bool is_better(int dist_a, const vector<string>& maze_a, int dist_b, const vector<string>& maze_b, int target_d) {
    if (dist_a == -1) return false;
    if (dist_b == -1) return true;

    int diff_a = abs(dist_a - target_d);
    int diff_b = abs(dist_b - target_d);

    if (diff_a < diff_b) return true;
    if (diff_a == diff_b && dist_a > dist_b) return true;
    return false;
}

signed main() {
    fastio();
    docfile();

    auto start_time = chrono::high_resolution_clock::now();

    int d;
    cin >> m >> n >> d;

    vector<string> initial_maze(m);
    vector<pair<int, int>> vec;

    for (int i = 0; i < m; ++i) {
        cin >> initial_maze[i];
        for (int j = 0; j < n; ++j) {
            if (initial_maze[i][j] == '.' && !(i == 0 && j == 0) && !(i == m - 1 && j == n - 1)) {
                vec.push_back({i, j});
            }
        }
    }

    maze = initial_maze;
    int initial_dist = bfs();

    vector<string> overall_best_maze = initial_maze;
    int overall_best_dist = initial_dist;

    if (overall_best_dist == d) {
        for (int i = 0; i < m; ++i) {
            cout << overall_best_maze[i] << ln;
        }
        return 0;
    }

    std::mt19937 g(std::random_device{}());

    while (true) {
        auto current_time = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = current_time - start_time;
        if (elapsed.count() > 0.97) {
            break;
        }

        maze = initial_maze;
        vector<string> run_best_maze = initial_maze;
        int run_best_dist = initial_dist;

        bool changed_in_pass = true;
        while (changed_in_pass) {
            changed_in_pass = false;
            int current_dist_start_pass = bfs();

            if (current_dist_start_pass == -1) break;

            if (is_better(current_dist_start_pass, maze, run_best_dist, run_best_maze, d)) {
                 run_best_dist = current_dist_start_pass;
                 run_best_maze = maze;
                 if (run_best_dist == d) goto end_run;
            }

            std::shuffle(vec.begin(), vec.end(), g);

            int dist_in_pass = current_dist_start_pass;

            for (const auto& i : vec) {
                int r = i.first;
                int c = i.second;

                if (maze[r][c] == '.') {
                    maze[r][c] = '#';
                    int new_dist = bfs();

                    if (new_dist != -1 && new_dist > dist_in_pass) {
                        dist_in_pass = new_dist;
                        changed_in_pass = true;

                         if (is_better(new_dist, maze, run_best_dist, run_best_maze, d)) {
                            run_best_dist = new_dist;
                            run_best_maze = maze;
                            if (run_best_dist == d) goto end_run;
                        }
                    } else {
                        maze[r][c] = '.';
                    }
                }
            }
        }

    end_run:;

        if (is_better(run_best_dist, run_best_maze, overall_best_dist, overall_best_maze, d)) {
            overall_best_dist = run_best_dist;
            overall_best_maze = run_best_maze;
            if (overall_best_dist == d) {
                break;
            }
        }

    }

    for (int i = 0; i < m; ++i) {
        cout << overall_best_maze[i] << ln;
    }

    time();
    return 0;
}