// Author: huythedev
// Problem Link: https://codeforces.com/contest/2113/problem/B
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
    ll w, h, a, b; cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    ll mod_x1 = ((x1 % a) + a) % a;
    ll mod_y1 = ((y1 % b) + b) % b;
    ll mod_x2 = ((x2 % a) + a) % a;
    ll mod_y2 = ((y2 % b) + b) % b;

    if ((y1 == y2 && mod_x1 != mod_x2) || (x1 == x2 && mod_y1 != mod_y2) || (mod_x1 != mod_x2 && mod_y1 != mod_y2)) {
        cout << "No" << ln;
    } else {
        cout << "Yes" << ln;
    }
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