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

ll ask(char direction, ll k) {
    cout << "? " << direction << " " << k << ln;
    cout.flush();
    ll s;
    cin >> s;
    return s;
}

void solve() {
    int n;
    cin >> n;

    ll maxU = LLONG_MIN;
    ll minV = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        maxU = max(maxU, x + y);
        minV = min(minV, x - y);
    }

    ll k = 1e9;

    ask('U', k);
    ll V = minV + 2 * k - ask('L', k);

    ask('R', k);
    ll U = ask('R', k) - 2 * k + maxU;

    ll X = (U + V) / 2, Y = (U - V) / 2;

    cout << "! " << X << " " << Y << ln;
    cout.flush();
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}