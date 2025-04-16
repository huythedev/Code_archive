// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6ancient
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6ancient"
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

const ll INF = 1LL << 60;

ll getBeauty(const vector<ll>& arr) {
    ll beauty = 0;
    for (int i = 1; i < arr.size(); i++) {
        beauty += abs(arr[i] - arr[i-1]);
    }
    return beauty;
}

ll type2_brute(const vector<ll>& arr) {
    int n = arr.size();
    ll maxBeauty = getBeauty(arr);
    
    for (int l = 0; l < n-1; l++) {
        for (int r = l+1; r < n; r++) {
            vector<ll> rotated = arr;
            
            rotated[l] = arr[r];
            for (int i = l+1; i <= r; i++) {
                rotated[i] = arr[i-1];
            }
            
            maxBeauty = max(maxBeauty, getBeauty(rotated));
        }
    }
    
    return maxBeauty;
}

struct Candidate {
    ll p, q;  
};

struct Node {
    Candidate min_p, max_p, min_q, max_q, min_diff;
};

vector<Node> tree;
int n;

Node merge(Node left, Node right) {
    Node res;
    res.min_p = (left.min_p.p < right.min_p.p) ? left.min_p : right.min_p;
    res.max_p = (left.max_p.p > right.max_p.p) ? left.max_p : right.max_p;
    res.min_q = (left.min_q.q < right.min_q.q) ? left.min_q : right.min_q;
    res.max_q = (left.max_q.q > right.max_q.q) ? left.max_q : right.max_q;
    ll left_diff = abs(left.min_diff.q - left.min_diff.p);
    ll right_diff = abs(right.min_diff.q - right.min_diff.p);
    res.min_diff = (left_diff < right_diff) ? left.min_diff : right.min_diff;
    return res;
}

void build(int node, int start, int end, const vector<ll>& a) {
    if (start == end) {
        ll p = a[start + 1], q = a[start + 2];
        tree[node].min_p = tree[node].max_p = tree[node].min_q = tree[node].max_q = tree[node].min_diff = {p, q};
    } 
    else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, a);
        build(2 * node + 1, mid + 1, end, a);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, Candidate val) {
    if (start == end) {
        tree[node].min_p = tree[node].max_p = tree[node].min_q = tree[node].max_q = tree[node].min_diff = val;
    } 
    else {
        int mid = (start + end) / 2;
        if (idx <= mid) 
            update(2 * node, start, mid, idx, val);
        else 
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

vector<Candidate> query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) 
        return {};
    if (l <= start && end <= r) {
        return {tree[node].min_p, tree[node].max_p, tree[node].min_q, tree[node].max_q, tree[node].min_diff};
    }
    int mid = (start + end) / 2;
    vector<Candidate> left = query(2 * node, start, mid, l, r);
    vector<Candidate> right = query(2 * node + 1, mid + 1, end, l, r);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    fastio();
    docfile();

    int N, Q; cin >> N >> Q;
    bool sub12 = (N <= 500 && Q <= 500);
    vector<ll> a(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> a[i];
    
    vector<ll> arr(N);
    if (sub12) {
        for (int i = 0; i < N; i++)
            arr[i] = a[i+1];
    }

    ll S = 0;
    for (int i = 1; i < N; i++) 
        S += abs(a[i + 1] - a[i]);

    n = N - 1;
    if (!sub12) {
        tree.resize(4 * n);
        if (N >= 2) 
            build(1, 0, n - 1, a);
    }

    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int p; ll x; cin >> p >> x;

            if (!sub12) {
                if (p > 1) 
                    S -= abs(a[p] - a[p - 1]);
                if (p < N) 
                    S -= abs(a[p + 1] - a[p]);

                a[p] = x;

                if (p > 1) 
                    S += abs(a[p] - a[p - 1]);
                if (p < N) 
                    S += abs(a[p + 1] - a[p]);
                if (p > 1) 
                    update(1, 0, n - 1, p - 2, {a[p - 1], a[p]});
                if (p < N) 
                    update(1, 0, n - 1, p - 1, {a[p], a[p + 1]});
            } else {
                arr[p-1] = x;
                a[p] = x; 
                S = getBeauty(arr); 
            }
        } 
        else {
            if (sub12) {
                cout << type2_brute(arr) << ln;
            } 
            else {
                ll tmp = 0;
                for (int r = 2; r <= N; r++) {
                    ll tmp2 = -abs(a[r] - a[r - 1]) + abs(a[1] - a[r]);
                    if (r < N) 
                        tmp2 += -abs(a[r + 1] - a[r]) + abs(a[r + 1] - a[r - 1]);
                    tmp = max(tmp, tmp2);
                }
                for (int l = 1; l < N; l++) {
                    ll tmp2 = 0;
                    if (l > 1) 
                        tmp2 += -abs(a[l] - a[l - 1]) + abs(a[N] - a[l - 1]);
                    tmp2 += -abs(a[N] - a[N - 1]) + abs(a[l] - a[N]);
                    tmp = max(tmp, tmp2);
                }
                for (int r = 3; r < N; r++) {
                    vector<Candidate> vec = query(1, 0, n - 1, 0, r - 3);
                    ll max_h = -INF;
                    for (auto cand : vec) {
                        ll h = -abs(cand.q - cand.p) + abs(a[r] - cand.p) + abs(cand.q - a[r]);
                        max_h = max(max_h, h);
                    }
                    ll ds = max_h - abs(a[r] - a[r - 1]) + abs(a[r + 1] - a[r - 1]) - abs(a[r + 1] - a[r]);
                    tmp = max(tmp, ds);
                }
                cout << S + max(0LL, tmp) << ln;
            }
        }
    }

    time();
    return 0;
}