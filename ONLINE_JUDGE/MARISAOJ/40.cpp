// Author: huythedev
// Problem Link: https://marisaoj.com/problem/40
#include <bits/stdc++.h>
using namespace std;

#define NAME "40"
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

const int LIM = 1e2 + 5;

void solve() {
    int n; cin >> n;
    vector<vector<bool>> covered(LIM, vector<bool>(LIM, false));
    
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                covered[x][y] = true;
            }
        }
    }
    
    int count = 0;
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            if (covered[x][y]) {
                count++;
            }
        }
    }
    
    cout << count << ln;
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