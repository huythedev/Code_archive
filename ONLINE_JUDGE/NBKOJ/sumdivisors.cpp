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

const ll MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;

    ll ans = 0;
    for (ll i = 1, next; i <= n; i = next + 1) {
        ll q = n / i;
        next = n / q;
        ll cnt = next - i + 1;
        ll sum = ((i + next) % MOD) * (cnt % MOD) % MOD * ((MOD + 1) / 2) % MOD;
        ans = (ans + q % MOD * sum % MOD) % MOD;
    }

    cout << ans << ln;
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