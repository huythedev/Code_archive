// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

const int MAXN = 500005;

struct node {
    node *l, *r;
    ll sum;
};

node pool[MAXN * 20];
int idx;
node* roots[MAXN + 1];

node* newNode() {
    pool[idx].l = pool[idx].r = nullptr;
    pool[idx].sum = 0;
    return &pool[idx++];
}

void build(node*& curr, int tl, int tr) {
    curr = newNode();
    if (tl == tr) 
        return;
    
    int tm = tl + (tr - tl) / 2;

    build(curr -> l, tl, tm);
    build(curr -> r, tm + 1, tr);
}

void update(node*& curr, node* prev, int tl, int tr, int pos, int val) {
    curr = newNode();
    *curr = *prev;

    if (tl == tr) {
        curr -> sum = val;
        return;
    }

    int tm = tl + (tr - tl) / 2;
    if (pos <= tm)
        update(curr -> l, prev -> l, tl, tm, pos, val);
    else
        update(curr -> r, prev -> r, tm + 1, tr, pos, val);
    
    curr -> sum = (curr -> l ? curr -> l -> sum : 0) + (curr -> r ? curr -> r -> sum : 0);
}

ll query(node* u, node* v, int tl, int tr) {
    if (!u || !v) 
        return 0;
    
    if (u == v) 
        return u -> sum;
    
    if (tl == tr)
        return (u -> sum > 0 && v -> sum > 0) ? tl : 0;

    int tm = tl + (tr - tl) / 2;
    return query(u -> l, v -> l, tl, tm) + query(u -> r, v -> r, tm + 1, tr);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    build(roots[0], 1, n);

    vector<int> vec(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int val = a[i];
        int newVal = 0;
        if (vec[val] == 0)
            newVal = val;
        else
            newVal = 0;
        
        update(roots[i + 1], roots[i], 1, n, val, newVal);

        vec[val] = newVal;
    }

    ll ans = 0;
    vector<ll> res;
    res.reserve(q);

    for (int i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        x = (x - 1 + ans) % n + 1;
        y = (y - 1 + ans) % n + 1;
        
        int l = min(x, y);
        int r = max(x, y);
        l--;

        ll tmp = (l == 0) ? 0 : query(roots[l], roots[r], 1, n);
        ans = (roots[r] -> sum) + ((l == 0) ? 0 : roots[l] -> sum) - 2 * tmp;

        res.push_back(ans);
    }
    
    for (ll x : res) cout << x << ' ';
    cout << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        idx = 0;
        solve();
    }

    time();
    return 0;
}
