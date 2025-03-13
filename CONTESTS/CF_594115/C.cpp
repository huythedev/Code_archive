// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/C
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

const int maxn = 105;
const int maxk = 100005;

int n, k;
vector<pair<int, int>> positions;

bool can_shoot_all(int x, int y) {
    for (auto [x2, y2] : positions) {
        if (x == x2) continue;
        if (y == y2) continue;
        if (x - y == x2 - y2) continue;
        if (x + y == x2 + y2) continue;
        return false;
    }
    return true;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> k;
    positions.resize(k);
    for (int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        positions[i] = {x - 1, y - 1}; 
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (can_shoot_all(i, j)) ++res;
        }
    }

    cout << res << ln;

    time();
    return 0;
}