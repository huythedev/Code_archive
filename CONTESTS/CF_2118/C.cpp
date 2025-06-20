// Author: huythedev
// Problem Link: https://codeforces.com/contest/2118/problem/C
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    ll res = 0;
    vector<ll> vec2(64, 0);
    for (ll i : a) {
        res += __builtin_popcountll(i);
        for (int pos = 0; pos < 64; pos++) {
            if (!(i & (1LL << pos))) {
                vec2[pos]++;
            }
        }
    }

    ll remain = k;
    for (int i = 0; i < 64; i++) {
        ll cost = 1LL << i; 
        ll tmp = min(remain / cost, vec2[i]);

        res += tmp;
        remain -= tmp * cost;
    }

    cout << res << ln;
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