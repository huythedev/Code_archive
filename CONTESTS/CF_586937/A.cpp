// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/586937/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

const ll N = 1e5 + 5;
ll tree[4 * N];
ll a[N];

void build(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(ll node, ll start, ll end, ll pos, ll val) {
    if (start == end) {
        tree[node] = val;
        a[pos] = val;
        return;
    }
    ll mid = (start + end) / 2;
    if (pos <= mid)
        update(2 * node, start, mid, pos, val);
    else
        update(2 * node + 1, mid + 1, end, pos, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + 
           query(2 * node + 1, mid + 1, end, l, r);
}

void type1(ll n) {
    ll pos, val; 
    cin >> pos >> val;
    update(1, 1, n, pos, val);
}

void type2(ll n) {
    ll l, r; 
    cin >> l >> r;
    cout << query(1, 1, n, l, r) << "\n";
}

int main() {
    fastio();
    docfile();

    ll n, q; 
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    
    build(1, 1, n);
    
    while (q--) {
        ll type; 
        cin >> type;
        if (type == 1) 
            type1(n);
        else 
            type2(n);
    }

    time();
    return 0;
}