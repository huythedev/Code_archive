// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    int n, s; cin >> n >> s;
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int dx, dy, x, y; cin >> dx >> dy >> x >> y;
        int tmp = dx * dy;

        if (tmp == 1 && y == x) 
            cnt++;
        else if (tmp == -1 && y + x == s) 
            cnt++;
    }

    cout << cnt << ln;
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