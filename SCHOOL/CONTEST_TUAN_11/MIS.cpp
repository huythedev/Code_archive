// Author: Perry
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MIS"
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

class FenwickTree {
private:
    vector<ll> tree;
    int n;
public:
    FenwickTree(int _n) {
        n = _n;
        tree.assign(n + 1, 0);
    }
    void update(int idx, ll val) {
        while (idx <= n) {
            tree[idx] = max(tree[idx], val);
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll res = 0;
        while (idx > 0) {
            res = max(res, tree[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) 
        cin >> A[i];

    vector<int> luck(n);
    for (int i = 0; i < n; ++i) 
        luck[i] = A[i] % 100;

    set<int> unique_A(A.begin(), A.end());
    vector<int> sorted_unique(unique_A.begin(), unique_A.end());
    map<int, int> rank_map;
    for (int i = 0; i < (int)sorted_unique.size(); ++i) {
        rank_map[sorted_unique[i]] = i + 1; 
    }
    int U = sorted_unique.size();

    FenwickTree fenwick(U + 1);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int rank = rank_map[A[i]];
        ll max_prev = fenwick.query(rank - 1);
        ll dp_i = luck[i] + max_prev;
        fenwick.update(rank, dp_i);
        ans = max(ans, dp_i);
    }

    cout << ans << ln;

    time();
    return 0;
}
