// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "G"
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

const int OFFSET = 200000;
const int MAXD = 400010;

ll cnt[MAXD + 2], sum[MAXD + 2], sum2[MAXD + 2];
vector<int> cnt2, sum3, sum4;

void add(ll* fen, int n, int idx, ll val, vector<int>& vec) {
    idx++;
    while (idx <= n) {
        fen[idx] += val;
        vec.push_back(idx);
        idx += idx & -idx;
    }
}

ll query(ll* fen, int idx) {
    idx++;
    ll res = 0;
    while (idx > 0) {
        res += fen[idx];
        idx -= idx & -idx;
    }
    return res;
}

void solve() {
    int n; string s; cin >> n >> s;

    cnt2.clear();
    sum3.clear();
    sum4.clear();

    vector<ll> prefix(n + 1, 0);
    vector<ll> prefix2(n + 1, 0);
    vector<ll> d(n + 1, 0);

    add(cnt, MAXD, OFFSET, 1, cnt2);
    add(sum, MAXD, OFFSET, 0, sum3);
    add(sum2, MAXD, OFFSET, 0, sum4);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            prefix[i] = prefix[i - 1] + 1;
            prefix2[i] = prefix2[i - 1];
            d[i] = d[i - 1] + 1;
        } else {
            prefix[i] = prefix[i - 1];
            prefix2[i] = prefix2[i - 1] + 1;
            d[i] = d[i - 1] - 1;
        }

        int idx = d[i] + OFFSET;
        ll count = query(cnt, idx);

        ans += (prefix[i] * count - query(sum, idx) + 
                prefix2[i] * (i - count) - 
                (query(sum2, MAXD - 1) - query(sum2, idx)));

        add(cnt, MAXD, idx, 1, cnt2);
        add(sum, MAXD, idx, prefix[i], sum3);
        add(sum2, MAXD, idx, prefix2[i], sum4);
    }

    cout << ans << ln;

    for (int idx : cnt2) cnt[idx] = 0;
    for (int idx : sum3) sum[idx] = 0;
    for (int idx : sum4) sum2[idx] = 0;
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