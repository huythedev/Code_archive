// Author: huythedev
// Problem Link: 
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

void solve() {
    int n;
    cin >> n;

    vector<ll> p(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (p[i - 1] % p[i] != 0) ok = false;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] % s[i] != 0) ok = false;
    }

    if (p[n - 1] != s[0]) ok = false;

    if (n >= 2) {
        if (gcd(p[0], s[1]) != s[0]) ok = false;
        if (gcd(p[n - 2], s[n - 1]) != p[n - 1]) ok = false;
    }

    for (int i = 1; i < n - 1; i++) {
        if (!ok) break;

        ll tmp = lcm(p[i], s[i]);

        if (gcd(p[i - 1], tmp) != p[i]) ok = false;
        if (gcd(tmp, s[i + 1]) != s[i]) ok = false;
    }
    
    cout << (ok ? "YES" : "NO") << ln;
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