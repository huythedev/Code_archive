// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI2"
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

vector<int> p;
map<pair<int, int>, int> mp, mp2;

int f(int l, int r) {
    if (l > r) return 0;

    if (mp2[{l, r}]) {
        return mp2[{l, r}];
    }

    int m = INT_MIN, m_idx = 0;
    if (mp[{l, r}]) {
        m_idx = mp[{l, r}];
    }
    else {
        for (int i = l; i <= r; ++i) {
            if (p[i] > m) {
                m = p[i];
                m_idx = i;
            }
        }
        mp[{l, r}] = m_idx;
    }

    int res = (r - l + 1) + f(l, m_idx - 1) + f(m_idx + 1, r);
    mp2[{l, r}] = res;

    return res;
}

int fIncrease(int l, int r) {
    if (l > r) return 0;
    
    ll n = r - l + 1;
    return (int)(n * (n + 1) / 2);
}

int fDecrease(int l, int r) {
    if (l > r) return 0;
    
    ll n = r - l + 1;
    return (int)(n * (n + 1) / 2);
}

void solve() {
    int n, q; cin >> n >> q;
    p.resize(n + 1);
    bool isIncreasing = true, isDecreasing = true;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (i >= 2) {
            if (p[i] < p[i - 1]) {
                isIncreasing = false;
            }
            else if (p[i] > p[i - 1]) {
                isDecreasing = false;
            }
        }
    }
    vector<int> l(q + 1), r(q + 1);
    for (int i = 1; i <= q; ++i) cin >> l[i];
    for (int i = 1; i <= q; ++i) cin >> r[i];

    if (isIncreasing || isDecreasing) {
        for (int i = 1; i <= q; ++i) {
            int len = r[i] - l[i] + 1;
            cout << (ll)len * (len + 1) / 2 << ' ';
        }
    }
    else {
        for (int i = 1; i <= q; ++i) {
            cout << f(l[i], r[i]) << ' ';
        }
    }
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