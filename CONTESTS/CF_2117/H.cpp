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

struct Node {
    map<int, int> freq; // Element -> frequency
};

// Merge two nodes, limiting candidates to O(log n)
Node merge(const Node& left, const Node& right, int n) {
    Node result = left;
    for (const auto& [x, f] : right.freq) {
        result.freq[x] += f;
    }
    // Prune to keep at most 2 * log2(n) candidates
    int max_candidates = 2 * (int)(log2(n) + 1);
    if (result.freq.size() > max_candidates) {
        vector<pair<int, int>> items(result.freq.begin(), result.freq.end());
        sort(items.begin(), items.end(), [](auto a, auto b) { return a.second > b.second; });
        result.freq.clear();
        for (int i = 0; i < max_candidates && i < items.size(); ++i) {
            result.freq[items[i].first] = items[i].second;
        }
    }
    return result;
}

class SegmentTree {
    vector<Node> tree;
    int n;

public:
    SegmentTree(int n) : n(n), tree(4 * n) {}

    void build(const vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node].freq[a[start]] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], n);
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node].freq.clear();
            tree[node].freq[val] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(idx, val, 2 * node, start, mid);
        else update(idx, val, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], n);
    }

    const map<int, int>& get_root_freq() const {
        return tree[1].freq;
    }
};

// Compute floor((length + 1) / 2)
inline int threshold(int length) {
    return (length + 1) / 2;
}

// Compute maximum k using binary search on frequency runs
int compute_max_k(const vector<int>& a) {
    int n = a.size();
    int max_k = 0;
    for (int num = 1; num <= n; ++num) {
        vector<int> pos;
        pos.push_back(-1); // Sentinel
        for (int i = 0; i < n; ++i) {
            if (a[i] == num) pos.push_back(i);
        }
        pos.push_back(n); // Sentinel
        for (int i = 1; i < pos.size() - 1; ++i) {
            int left = pos[i - 1] + 1;
            int right = pos[i + 1] - 1;
            int freq = i;
            int lo = pos[i] - left + 1;
            int hi = right - left + 1;
            while (lo <= hi) {
                int len = (lo + hi) / 2;
                int t = threshold(len);
                if (freq >= t) {
                    max_k = max(max_k, freq - t);
                    lo = len + 1;
                } else {
                    hi = len - 1;
                }
            }
        }
    }
    return max_k;
}

void solve() {
    int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        SegmentTree st(n);
        st.build(a, 1, 0, n - 1);
        vector<int> answers;
        for (int j = 0; j < q; ++j) {
            int i, x;
            cin >> i >> x;
            --i; // 0-based indexing
            a[i] = x;
            st.update(i, x, 1, 0, n - 1);
            int k = compute_max_k(a);
            answers.push_back(k);
        }
        for (int j = 0; j < q; ++j) {
            cout << answers[j] << (j < q - 1 ? " " : "\n");
        }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}