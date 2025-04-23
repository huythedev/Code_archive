// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/segtree_itez2

#include <bits/stdc++.h>
using namespace std;

#define NAME "segtree_itez2"
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

const int MAXN = 1e5 + 5;
ll segtree[4 * MAXN];
ll arr[MAXN];
int n, q;

void build(int id, int l, int r) {
    if (l == r) {
        segtree[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

void update(int id, int l, int r, int pos, ll val) {
    if (l == r) {
        segtree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    segtree[id] = segtree[id * 2] + segtree[id * 2 + 1];
}

ll query(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return segtree[id];
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    fastio();
    docfile();

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) arr[i] = 0;
    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            ll val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << ln;
        }
    }

    time();
    return 0;
}