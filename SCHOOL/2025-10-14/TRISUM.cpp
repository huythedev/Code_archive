// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TRISUM"
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

const ll MOD = 1e9 + 7;

struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick() {}
    Fenwick(int n_): n(n_), t(n_ + 1, 0) {}
    void reset(int n_) { n = n_; t.assign(n + 1, 0); }
    void add(int i, ll v) {
        for (; i <= n; i += i & -i) t[i] += v;
    }
    ll sumPrefix(int i) const {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto idx = [&](ll x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };
    int m = (int)vals.size();

    Fenwick bitCnt(m), bitSum(m);

    vector<ll> L(n, 0);
    ll totCnt = 0, totSum = 0;
    for (int k = 0; k < n; ++k) {
        int id = idx(a[k]);
        ll cntLE  = bitCnt.sumPrefix(id);
        ll sumLE  = bitSum.sumPrefix(id);
        ll cntGT  = totCnt - cntLE;
        ll sumGT  = totSum - sumLE;
        ll Lk = a[k] * cntLE - sumLE + (sumGT - a[k] * cntGT);
        L[k] = Lk;

        bitCnt.add(id, 1);
        bitSum.add(id, a[k]);
        ++totCnt;
        totSum += a[k];
    }

    bitCnt = Fenwick(m);
    bitSum = Fenwick(m);
    totCnt = 0; totSum = 0;
    ll ans = 0;

    for (int k = n - 1; k >= 0; --k) {
        int id = idx(a[k]);
        ll cntLE  = bitCnt.sumPrefix(id);
        ll sumLE  = bitSum.sumPrefix(id);
        ll cntGT  = totCnt - cntLE;
        ll sumGT  = totSum - sumLE;
        ll Rk = a[k] * cntLE - sumLE
                     + (sumGT - a[k] * cntGT);

        ll add = ((L[k] % MOD + MOD) % MOD) * ((Rk % MOD + MOD) % MOD) % MOD;
        ans += add;
        if (ans >= MOD) ans -= MOD;

        bitCnt.add(id, 1);
        bitSum.add(id, a[k]);
        ++totCnt;
        totSum += a[k];
    }

    cout << (ans % MOD + MOD) % MOD << ln;
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