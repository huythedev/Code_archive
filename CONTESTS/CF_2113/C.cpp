// Author: huythedev
// Problem Link: https://codeforces.com/contest/2113/problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    set<pair<int, int>> st;
    auto ok = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (a[x][y] == '.') {
                for (int dx = -k; dx <= k; dx++) {
                    for (int dy = -k; dy <= k; dy++) {
                        if (max(abs(dx), abs(dy)) == k) {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (ok(nx, ny) && a[nx][ny] == 'g') {
                                st.insert({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }

    cout << st.size() << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}