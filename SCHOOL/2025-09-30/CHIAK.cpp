// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CHIAK"
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

static inline ll norm_mod(ll x, ll k) {
    x %= k;
    if (x < 0) x += k;
    return x;
}

void solve() {
    int n; ll k;
    if (!(cin >> n >> k)) return;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    unordered_map<ll, ll> cnt;
    cnt.reserve((size_t)min<long long>(n + 5LL, 2000000LL));
    cnt.max_load_factor(0.7f);

    ll pref = 0;
    ll ans = 0;
    cnt[0] = 1; // tổng rỗng

    for (int i = 0; i < n; ++i) {
        pref = (pref + norm_mod(a[i], k)) % k;
        auto it = cnt.find(pref);
        if (it != cnt.end()) {
            ans += it->second;
            ++(it->second);
        } else {
            cnt[pref] = 1;
        }
    }

    cout << ans << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
