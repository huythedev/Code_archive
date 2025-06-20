// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "H"
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

const int MAXN = 4e5 + 10;

struct segtree {
    vector<int> tree, lazy;
    int n;

    segtree(int _n) : n(_n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

    void add(int l, int r) {
        update(1, 1, n, l, r, 1);
    }

    int get() {
        return query(1, 1, n, 1, n);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        vec.push_back(l[i]);
        vec.push_back(r[i]);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    int m = vec.size();
    map<int, int> mp;
    for (int i = 0; i < m; ++i) 
        mp[vec[i]] = i + 1;
    
    segtree st(m);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int li = mp[l[i]];
        int ri = mp[r[i]];
        st.add(li, ri);
        ans[i] = st.get();
    }

    for (int i = 0; i < n; ++i) 
        cout << ans[i] << " ";
    
    cout << ln;
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