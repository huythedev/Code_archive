// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc3
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc3"
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

const ll INF = 1e18;

class FenwickTree {
private:
    vector<ll> tree;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    void update(int idx, ll val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    fastio();
    docfile();

    int n, k, X;
    cin >> n >> k >> X;
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }

    vector<ll> all_prefix = prefix;
    sort(all_prefix.begin(), all_prefix.end());
    all_prefix.erase(unique(all_prefix.begin(), all_prefix.end()), all_prefix.end());
    int N = all_prefix.size();
    auto get_rank = [&](ll val) {
        return lower_bound(all_prefix.begin(), all_prefix.end(), val) - all_prefix.begin() + 1;
    };

    auto compute = [&](ll S, bool final = false) {
        FenwickTree fenwick_count(N);
        FenwickTree fenwick_sum(N);
        fenwick_count.update(get_rank(prefix[0]), 1);
        fenwick_sum.update(get_rank(prefix[0]), prefix[0]);

        ll m = 0;  
        ll p = 0;  
        ll sum_gt = 0;  

        for (int j = 1; j <= n; ++j) {
            if (j >= X) {
                ll V = prefix[j] - S;
                int rank_V = upper_bound(all_prefix.begin(), all_prefix.end(), V) - all_prefix.begin();
                ll count_ge = fenwick_count.query(rank_V);
                ll sum_ge = fenwick_sum.query(rank_V);
                m += count_ge;

                ll W = prefix[j] - S;
                int rank_strict = lower_bound(all_prefix.begin(), all_prefix.end(), W) - all_prefix.begin();
                ll count_strict = fenwick_count.query(rank_strict);
                ll sum_strict = fenwick_sum.query(rank_strict);
                p += count_strict;
                sum_gt += prefix[j] * count_strict - sum_strict;
            }
            fenwick_count.update(get_rank(prefix[j]), 1);
            fenwick_sum.update(get_rank(prefix[j]), prefix[j]);
        }
        return make_tuple(m, p, sum_gt);
    };

    ll low = -INF;
    ll high = INF;
    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        auto [m, _, __] = compute(mid);
        if (m >= k) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    ll S = low;

    auto [_, p, sum_gt] = compute(S, true);
    ll total_sum = sum_gt + (k - p) * S;

    cout << total_sum << endl;

    time();
    return 0;
}