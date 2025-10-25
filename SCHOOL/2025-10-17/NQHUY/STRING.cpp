// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "STRING"
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

const int MAXN = 200005;

int n, q;
string s;
vector<pair<int, int>> queriesR[MAXN];
vector<pair<int, int>> queriesL[MAXN];
ll bit[MAXN];
ll ans[MAXN];

void update(int idx, ll val) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}

ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

ll queryRange(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
}

void resetBit() {
    for (int i = 0; i <= n; ++i) {
        bit[i] = 0;
    }
}

void solve() {
    cin >> n >> q;
    cin >> s;

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queriesR[r].push_back({l, i});
        queriesL[l].push_back({r, i});
    }

    vector<int> lastPos(26, 0);
    for (int r = 1; r <= n; ++r) {
        int char_idx = s[r - 1] - 'a';
        if (lastPos[char_idx] != 0) {
            update(lastPos[char_idx], -lastPos[char_idx]);
        }
        update(r, r);
        lastPos[char_idx] = r;

        for (const pair<int, int>& query : queriesR[r]) {
            int l = query.first;
            int query_idx = query.second;
            ans[query_idx] += queryRange(l, r);
        }
    }

    resetBit();

    vector<int> firstPos(26, 0);
    for (int l = n; l >= 1; --l) {
        int char_idx = s[l - 1] - 'a';
        if (firstPos[char_idx] != 0) {
            update(firstPos[char_idx], -firstPos[char_idx]);
        }
        update(l, l);
        firstPos[char_idx] = l;
        
        for (const pair<int, int>& query : queriesL[l]) {
            int r = query.first;
            int idx = query.second;
            ans[idx] -= queryRange(l, r);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << ln;
    }
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