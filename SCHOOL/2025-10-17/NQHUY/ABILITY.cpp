// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ABILITY"
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

const int MAXN = 100005;

int n, q;
int a[MAXN];
vector<pair<int, int>> queries[MAXN];
int ans[MAXN];
int segTree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        segTree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

int query(int node, int start, int end, int l_val) {
    if (segTree[node] >= l_val) {
        return -1;
    }
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int res = query(2 * node, start, mid, l_val);
    if (res != -1) {
        return res;
    }
    return query(2 * node + 1, mid + 1, end, l_val);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }

    build(1, 0, n);

    for (int r = 1; r <= n; ++r) {
        if (a[r] <= n) {
            update(1, 0, n, a[r], r);
        }
        for (const pair<int, int>& qr : queries[r]) {
            int l = qr.first;
            int idx = qr.second;
            ans[idx] = query(1, 0, n, l);
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