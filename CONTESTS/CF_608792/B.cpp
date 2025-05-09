// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608792/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
#define ln "\n"

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

const int MAXN_ST = 2e5 + 5; 
const ll HASH_B = 31;       
const ll HASH_P = 1e9 + 7;  

ll power(ll base, ll exp_val) {
    ll res = 1;
    base %= HASH_P; 
    if (base < 0) base += HASH_P;

    ll p_exp; 
    if (exp_val < 0) {
        ll inv_base = 1;
        ll temp_b_for_inv = base;
        ll exp_for_inv = HASH_P - 2; 
        while(exp_for_inv > 0) {
            if(exp_for_inv % 2 == 1) inv_base = (inv_base * temp_b_for_inv) % HASH_P;
            temp_b_for_inv = (temp_b_for_inv * temp_b_for_inv) % HASH_P;
            exp_for_inv /= 2;
        }
        base = inv_base;
        p_exp = -exp_val;
    } else {
        p_exp = exp_val;
    }

    while (p_exp > 0) {
        if (p_exp % 2 == 1) res = (res * base) % HASH_P;
        base = (base * base) % HASH_P;
        p_exp /= 2;
    }
    return res;
}

ll sum_val_tree[4 * MAXN_ST];
ll hash_fwd_tree[4 * MAXN_ST];
ll hash_bwd_tree[4 * MAXN_ST];
int len_tree[4 * MAXN_ST];
ll lazy_add[4 * MAXN_ST]; 

void apply_delta_to_node(int node_idx, ll delta) {
    if (delta == 0) return;

    sum_val_tree[node_idx] += delta * len_tree[node_idx];

    ll B_pow_delta = power(HASH_B, delta);
    ll B_pow_minus_delta = power(HASH_B, -delta); 

    hash_fwd_tree[node_idx] = (hash_fwd_tree[node_idx] * B_pow_delta) % HASH_P;
    hash_bwd_tree[node_idx] = (hash_bwd_tree[node_idx] * B_pow_minus_delta) % HASH_P;
}

void push(int node) {
    if (lazy_add[node] == 0) return;
    if (len_tree[node] == 1) { 
        lazy_add[node] = 0; 
        return;
    }

    ll delta_to_push = lazy_add[node];

    apply_delta_to_node(node * 2, delta_to_push);
    lazy_add[node * 2] += delta_to_push;

    apply_delta_to_node(node * 2 + 1, delta_to_push);
    lazy_add[node * 2 + 1] += delta_to_push;
    
    lazy_add[node] = 0;
}

void build(int node, int start, int end, const vector<int>& initial_array) {
    lazy_add[node] = 0;
    len_tree[node] = end - start + 1;
    if (start == end) {
        ll val = initial_array[start];
        sum_val_tree[node] = val;
        hash_fwd_tree[node] = power(HASH_B, val);
        hash_bwd_tree[node] = power(HASH_B, -val); 
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid, initial_array);
        build(node * 2 + 1, mid + 1, end, initial_array);
        
        sum_val_tree[node] = sum_val_tree[node * 2] + sum_val_tree[node * 2 + 1];
        hash_fwd_tree[node] = (hash_fwd_tree[node * 2] + hash_fwd_tree[node * 2 + 1]) % HASH_P;
        hash_bwd_tree[node] = (hash_bwd_tree[node * 2] + hash_bwd_tree[node * 2 + 1]) % HASH_P;
    }
}

void update_range_add(int node, int start, int end, int l, int r, int val_add) {
    if (start > end || start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) { 
        apply_delta_to_node(node, val_add); 
        lazy_add[node] += val_add;          
        return;
    }

    push(node); 

    int mid = (start + end) / 2;
    update_range_add(node * 2, start, mid, l, r, val_add);
    update_range_add(node * 2 + 1, mid + 1, end, l, r, val_add);

    sum_val_tree[node] = sum_val_tree[node * 2] + sum_val_tree[node * 2 + 1];
    hash_fwd_tree[node] = (hash_fwd_tree[node * 2] + hash_fwd_tree[node * 2 + 1]) % HASH_P;
    hash_bwd_tree[node] = (hash_bwd_tree[node * 2] + hash_bwd_tree[node * 2 + 1]) % HASH_P;
}

std::tuple<ll, ll, ll, int> query_range(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) {
        return {0, 0, 0, 0};
    }

    if (start >= l && end <= r) { 
        return {sum_val_tree[node], hash_fwd_tree[node], hash_bwd_tree[node], len_tree[node]};
    }

    push(node); 

    int mid = (start + end) / 2;
    auto p1_tuple = query_range(node * 2, start, mid, l, r);
    auto p2_tuple = query_range(node * 2 + 1, mid + 1, end, l, r);
    
    ll p1_sum, p1_fwd, p1_bwd;
    int p1_len;
    std::tie(p1_sum, p1_fwd, p1_bwd, p1_len) = p1_tuple;

    ll p2_sum, p2_fwd, p2_bwd;
    int p2_len;
    std::tie(p2_sum, p2_fwd, p2_bwd, p2_len) = p2_tuple;

    if (p1_len == 0) return p2_tuple;
    if (p2_len == 0) return p1_tuple;

    ll merged_sum = p1_sum + p2_sum;
    ll merged_fwd = (p1_fwd + p2_fwd) % HASH_P;
    ll merged_bwd = (p1_bwd + p2_bwd) % HASH_P;
    int merged_len = p1_len + p2_len;
    
    return {merged_sum, merged_fwd, merged_bwd, merged_len};
}

void type1(int l, int r, int val, int n) {
    update_range_add(1, 0, n - 1, l - 1, r - 1, val);
}

void type2(int l_orig, int r_orig, int n_array) {
    int l_idx = l_orig - 1; 
    int r_idx = r_orig - 1; 
    
    int current_len = r_idx - l_idx + 1;

    if (current_len <= 0) {
        cout << "YES" << ln;
        return;
    }

    if (current_len % 2 != 0) {
        cout << "NO" << ln;
        return;
    }

    auto range_data_tuple = query_range(1, 0, n_array - 1, l_idx, r_idx);
    
    ll S = std::get<0>(range_data_tuple);
    ll current_hash_fwd = std::get<1>(range_data_tuple);
    ll current_hash_bwd = std::get<2>(range_data_tuple);

    int k = current_len / 2;

    if (S % k != 0) { 
        cout << "NO" << ln;
        return;
    }
    ll M = S / k;
    
    ll B_pow_M = power(HASH_B, M);

    ll target_H_rev = (B_pow_M * current_hash_bwd) % HASH_P;
    if (target_H_rev < 0) target_H_rev += HASH_P; 

    if (current_hash_fwd == target_H_rev) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

signed main() {
    fastio();
    docfile();

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    build(1, 0, n - 1, a);
    
    while (q--) {
        int type_val; cin >> type_val;
        if (type_val == 1) {
            int l, r, v; cin >> l >> r >> v;
            type1(l, r, v, n);
        } else if (type_val == 2) {
            int l, r; cin >> l >> r;
            type2(l, r, n);
        }
    }

    time();
    return 0;
}