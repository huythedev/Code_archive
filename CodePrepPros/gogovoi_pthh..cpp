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

const int MAXN = 2e5 + 5;

vector<ll> a(MAXN);
vector<ll> prefixSum(MAXN);
int n, k;

ll inc(ll t, int s) {
    return 1LL * s * t - prefixSum[s];
}

ll dec(ll t, int r) {
    return (prefixSum[n] - prefixSum[n - r]) - 1LL * r * t;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (ll &x : a) cin >> x;
    
    sort(a.begin(), a.end());
    
    prefixSum.resize(n + 1);
    for (int i = 1; i <= n; ++i) 
        prefixSum[i] = prefixSum[i - 1] + a[i - 1];

    ll ans = (1LL << 62);
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == a[i]) 
            ++j;

        int need = max(0, k - (j - i));
        if (need == 0) {
            cout << 0 << ln;
            return;
        }

        int lo = max(0, need - (n - j));
        int hi = min(need, i);
        if (lo <= hi) {
            auto cost = [&](int s) -> ll {
                return inc(a[i], s) + dec(a[i], need - s);
            };
            ans = min(ans, min(cost(lo), cost(hi)));
        }

        i = j;
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
