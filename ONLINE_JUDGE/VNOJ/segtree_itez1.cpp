// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/segtree_itez1
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "segtree_itez1"
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

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MIN;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);
        return max(left_query, right_query);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree segtree(a);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            segtree.update(pos - 1, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segtree.query(l - 1, r - 1) << ln;
        }
    }

    time();
    return 0;
}