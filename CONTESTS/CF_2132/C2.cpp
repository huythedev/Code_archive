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

ll calc (ll n) {
    ll res = 0;
    while (n) {
        res += n % 3;
        n /= 3;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll s = calc(n);
    if (k < s) {
        cout << -1 << ln;
        return;
    }

    ll m = min(k, n);
    if ((m - s) & 1) {
        --m;
    }

    vector<ll> cnt(64, 0);
    cnt[0] = n;

    ll S = 0, pow3_i = 1;
    ll tmp = (n - m) / 2;

    for (ll i = 0; tmp > 0; ++i) {
        ll g = min(cnt[i] / 3, tmp);

        if (g > 0) {
            cnt[i] -= 3 * g;
            cnt[i + 1] += g;

            S += 1 * g * (pow3_i * 3);

            tmp -= g;
        }

        pow3_i *= 3;
    }

    ll ans = 3 * n + S / 3;

    cout << ans << ln;
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