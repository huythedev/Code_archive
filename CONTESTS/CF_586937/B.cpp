// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/586937/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

const int N = 1e5 + 5;
ll tree[4 * N], lazy[4 * N];
ll a[N];

void build(ll node, ll start, ll end) {
    lazy[node] = 0;
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void propagate(ll node, ll start, ll end) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(ll node, ll start, ll end, ll l, ll r, ll val) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r, val);
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query_range(ll node, ll start, ll end, ll l, ll r) {
    if (start > end || start > r || end < l) return 0;
    propagate(node, start, end);
    if (start >= l && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    return query_range(2 * node, start, mid, l, r) +
           query_range(2 * node + 1, mid + 1, end, l, r);
}

void type1(int n) {
    ll l, r, val;
    cin >> l >> r >> val;
    update_range(1, 1, n, l, r, val);
}

void type2(int n) {
    ll l, r;
    cin >> l >> r;
    cout << query_range(1, 1, n, l, r) << ln;
}

int main() {
    fastio();
    docfile();

    ll n, q; 
    cin >> n >> q;
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    
    build(1, 1, n);
    
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            type1(n);
        }
        else {
            type2(n);
        }
    }

    time();
    return 0;
}