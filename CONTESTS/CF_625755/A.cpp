// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

bool ok (ll a, ll b, ll x) {
    if (a == x || b == x) {
        return true;
    }

    if (a < b) {
        swap(a, b);
    }

    if (b == 0 || x > a) {
        return false;
    }

    if ((a - x) % b == 0) {
        return true;
    }

    return ok(b, a % b, x);
}

void solve() {
    ll a, b, x; cin >> a >> b >> x;

    if (x == a || x == b) {
        cout << "YES" << ln;
        return;
    }

    if (x > max(a, b)) {
        cout << "NO" << ln;
        return;
    }

    if (ok(a, b, x)) {
        cout << "YES" << ln;
    }
    else {
        cout << "NO" << ln;
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
