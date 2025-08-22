// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

struct Casino {
    ll l, r, real;
};

vector<ll> tree;
int tsz;

void build(int n) {
    tsz = 1;
    while (tsz < n) 
        tsz *= 2;
    tree.assign(2 * tsz, 0);
}

void update(int pos) {
    pos += tsz;
    tree[pos] = 1;
    pos /= 2;
    for (; pos >= 1; pos /= 2) {
        tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
    }
}

ll query(int l, int r) {
    ll res = 0;
    l += tsz; r += tsz;
    for (; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res, tree[l++]);
        if (r % 2 == 0) res = max(res, tree[r--]);
    }
    return res;
}

bool comp(const Casino& a, const Casino& b) {
    return a.real < b.real;
}

void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<Casino> vec(n);
    set<ll> st;
    st.insert(k);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].l >> vec[i].r >> vec[i].real;
        st.insert(vec[i].real);
    }

    vector<ll> vec2(st.begin(), st.end());
    int m = vec2.size();
    map<ll, int> mp;
    for (int i = 0; i < m; ++i) {
        mp[vec2[i]] = i;
    }

    build(m);
    update(mp[k]);
    sort(vec.begin(), vec.end(), comp);
    
    ll res = k;
    for (const auto& i : vec) {
        auto itl = lower_bound(vec2.begin(), vec2.end(), i.l);
        if (itl == vec2.end()) continue;

        int left = itl - vec2.begin();

        auto itr = upper_bound(vec2.begin(), vec2.end(), i.r);
        if (itr == vec2.begin()) continue;
        --itr;

        int right = itr - vec2.begin();

        if (left > right) 
            continue;

        if (query(left, right) == 1) {
            res = max(res, i.real);
            update(mp[i.real]);
        }
    }
    
    cout << res << ln;
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