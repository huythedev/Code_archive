// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin10_quanhau"
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

const int MAXSIZE = 8;
vector<vector<int>> matrix(MAXSIZE, vector<int>(MAXSIZE));

void print_table() {
    for (vector<int> i : matrix) {
        for (int x : i) cout << x << ' ';
        cout << ln;
    }
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        x--; y--;

        for (int i = 0; i < MAXSIZE; ++i) {
            matrix[i][y] = 1;
            matrix[x][i] = 1;
        }

        for (int dx = -MAXSIZE; dx <= MAXSIZE; ++dx) {
            int nx, ny;
            nx = x + dx; ny = y + dx;
            if (nx >= 0 && nx < MAXSIZE && ny >= 0 && ny < MAXSIZE) 
                matrix[nx][ny] = 1;

            nx = x + dx; ny = y - dx;
            if (nx >= 0 && nx < MAXSIZE && ny >= 0 && ny < MAXSIZE) 
                matrix[nx][ny] = 1;
        }
    }

    print_table();
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