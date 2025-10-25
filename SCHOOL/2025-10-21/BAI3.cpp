#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI3"
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

struct Node {
    ll val;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
    Node(ll v) : val(v) {}
};

struct Result {
    ll diff;
    ll sum;
    ll size;
};

Result solve2(Node* node) {
    if (node == nullptr) {
        return {0, 0, 0};
    }
    Result L = solve2(node->left);
    Result R = solve2(node->right);
    ll v = node->val;
    ll cross_LR = R.sum * L.size - L.sum * R.size;
    ll contrib_v_L = v * L.size - L.sum;
    ll contrib_v_R = v * R.size - R.sum;
    ll Q = (contrib_v_L - contrib_v_R) + cross_LR;
    ll my_diff = L.diff + R.diff + abs(Q);
    ll my_sum = L.sum + R.sum + v;
    ll my_size = L.size + R.size + 1;
    return {my_diff, my_sum, my_size};
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nodes[i] = new Node(a[i]);
    }
    stack<int> st;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int last_popped_idx = -1;
        while (!st.empty() && nodes[st.top()]->val < nodes[i]->val) {
            last_popped_idx = st.top();
            st.pop();
        }
        if (last_popped_idx != -1) {
            nodes[i]->left = nodes[last_popped_idx];
            nodes[last_popped_idx]->parent = nodes[i];
        }
        if (!st.empty()) {
            nodes[st.top()]->right = nodes[i];
            nodes[i]->parent = nodes[st.top()];
        }
        st.push(i);
    }
    if (n > 0) {
        root = nodes[0];
        while (root->parent != nullptr) {
            root = root->parent;
        }
    }
    Result res = solve2(root);
    ll C_n = (n * n * n - n) / 6;
    cout << (C_n + res.diff) / 2 << "\n";
    for (int i = 0; i < n; ++i) {
        delete nodes[i];
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}