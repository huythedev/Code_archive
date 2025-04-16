// Author: huythedev (https://huythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc4
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc4"
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
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}
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
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }

    ll min_sum = INF, max_sum = -INF;
    for (int r = X - 1; r < n; r++) {
        ll s = prefix[r + 1] - prefix[r + 1 - X];
        min_sum = min(min_sum, s);
        max_sum = max(max_sum, s);
    }

    vector<ll> all_prefix = prefix;
    sort(all_prefix.begin(), all_prefix.end());
    all_prefix.erase(unique(all_prefix.begin(), all_prefix.end()), all_prefix.end());
    int N = all_prefix.size();
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++) {
        rank[i] = lower_bound(all_prefix.begin(), all_prefix.end(), prefix[i]) - all_prefix.begin() + 1;
    }

    auto compute = [&](ll S) {
        FenwickTree fenwick_count(N);
        FenwickTree fenwick_sum(N);
        ll count_geq = 0;  
        ll sum_geq = 0;    
        ll count_exact = 0; 

        for (int r = 0; r <= n; r++) {
            if (r >= X) {
                ll target = prefix[r] - S;
                int pos = upper_bound(all_prefix.begin(), all_prefix.end(), target) - all_prefix.begin();
                count_geq += fenwick_count.query(pos);
                if (pos > 0) {
                    ll cnt = fenwick_count.query(pos - 1);
                    sum_geq += prefix[r] * cnt - fenwick_sum.query(pos - 1);
                }
            }
            if (r < n) {
                fenwick_count.update(rank[r], 1);
                fenwick_sum.update(rank[r], prefix[r]);
            }
        }
        return make_tuple(count_geq, sum_geq);
    };

    ll low = min_sum - 1, high = max_sum;
    ll S = low;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        auto [count_geq, _] = compute(mid);
        if (count_geq >= k) {
            S = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    auto [m, sum_gt] = compute(S);
    ll p = m - std::get<0>(compute(S + 1));
    ll total_sum = sum_gt + (k - (m - p)) * S;

    cout << total_sum << endl;

    time();
    return 0;
}