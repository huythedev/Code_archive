// Author: Perry
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "XEPGHE"
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

class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) updateHelper(2 * node, start, mid, idx, val);
        else updateHelper(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    int queryHelper(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return INT_MIN;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        int leftMax = queryHelper(2 * node, start, mid, left, right);
        int rightMax = queryHelper(2 * node + 1, mid + 1, end, left, right);
        return max(leftMax, rightMax);
    }
    
public:
    SegmentTree(int _n) : n(_n), tree(4 * _n, INT_MIN) {}
    
    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }
    
    int query(int left, int right) {
        if (left > right) return INT_MIN;
        return queryHelper(1, 0, n - 1, left, right);
    }
};

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    
    SegmentTree st(n);
    vector<vector<int>> add_at(n + 1);
    for (int j = 0; j < n; ++j) {
        int k = j + r[j] + 1;
        if (k <= n) add_at[k].push_back(j);
    }
    
    vector<int> dp(n, 0);
    int ans = 0;
    
    for (int i = 0; i <= n; ++i) {
        for (int j : add_at[i]) {
            st.update(j, dp[j]);
        }
        if (i < n) {
            if (i - l[i] <= 0) {
                dp[i] = 1;
            } else {
                int left = i - l[i] - 1;
                int max_prev = (left >= 0) ? st.query(0, left) : INT_MIN;
                dp[i] = (max_prev != INT_MIN) ? 1 + max_prev : 1;
            }
            ans = max(ans, dp[i]);
        }
    }
    
    cout << ans << ln;

    time();
    return 0;
}