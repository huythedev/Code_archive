#include <bits/stdc++.h>
using namespace std;

#define NAME "drsq"
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

vector<ll> tree;
int n;

void build(vector<int>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    build(arr, 2 * node, start, mid);
    build(arr, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return 0;
    if (l <= start && end <= r) return tree[node];
    
    int mid = (start + end) / 2;
    ll left_sum = query(2 * node, start, mid, l, r);
    ll right_sum = query(2 * node + 1, mid + 1, end, l, r);
    return left_sum + right_sum;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll rangeSum(int l, int r) {
    return query(1, 0, n - 1, l - 1, r - 1);
}

void updateValue(int idx, int val) {
    update(1, 0, n - 1, idx - 1, val);
}

int main() {
    fastio();
    docfile();

    int q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    tree.resize(4 * n);
    build(arr, 1, 0, n - 1);
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int p, v;
            cin >> p >> v;
            updateValue(p, v);
        } else {
            int l, r; cin >> l >> r;
            cout << rangeSum(l, r) << ln;
        }
    }

    time();
    return 0;
}
