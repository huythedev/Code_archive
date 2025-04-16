// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2078/problem/D
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

struct CompressedState {
    int l_log, r_log, i;
    
    bool operator==(const CompressedState& other) const {
        return l_log == other.l_log && r_log == other.r_log && i == other.i;
    }
};

namespace std {
    template<>
    struct hash<CompressedState> {
        size_t operator()(const CompressedState& s) const {
            return (size_t)s.l_log ^ ((size_t)s.r_log << 10) ^ ((size_t)s.i << 20);
        }
    };
}

ll solve(vector<pair<char,int>>& left, vector<pair<char,int>>& right, int n) {
    unordered_map<CompressedState, ll> memo;
    
    auto compress = [](ll val) -> int {
        if (val <= 0) return 0;
        if (val <= 100) return val; 
        if (val <= 10000) return 100 + log2(val - 100) * 10; 
        return 300 + log2(val - 10000) * 5; 
    };
    
    function<ll(ll,ll,int)> dp = [&](ll l, ll r, int i) {
        if (i == n) return l + r;
        
        CompressedState key = {compress(l), compress(r), i};
        if (memo.count(key)) return memo[key];
        
        ll gain_l = (left[i].first == '+') ? left[i].second : (l * (left[i].second - 1));
        ll gain_r = (right[i].first == '+') ? right[i].second : (r * (right[i].second - 1));
        ll total_gain = gain_l + gain_r;
        
        if (i < n-1) {
            bool next_l_mult = (left[i+1].first == 'x');
            bool next_r_mult = (right[i+1].first == 'x');
            
            if (next_l_mult && !next_r_mult) {
                return memo[key] = dp(l + total_gain, r, i+1);
            }
            if (!next_l_mult && next_r_mult) {
                return memo[key] = dp(l, r + total_gain, i+1);
            }
            
            if (next_l_mult && next_r_mult) {
                int l_mult = left[i+1].second;
                int r_mult = right[i+1].second;
                
                if (l_mult > r_mult + 1) {
                    return memo[key] = dp(l + total_gain, r, i+1);
                }
                if (r_mult > l_mult + 1) {
                    return memo[key] = dp(l, r + total_gain, i+1);
                }
            }
        }
        
        ll best = 0;
        
        if (total_gain <= 10) {
            for (ll k = 0; k <= total_gain; k++) {
                best = max(best, dp(l + k, r + (total_gain - k), i+1));
            }
        } else if (total_gain <= 100) {
            vector<double> ratios = {0, 0.1, 0.25, 0.33, 0.5, 0.67, 0.75, 0.9, 1.0};
            ll best_k = 0;
            ll best_val = 0;
            
            for (double ratio : ratios) {
                ll k = round(ratio * total_gain);
                ll val = dp(l + k, r + (total_gain - k), i+1);
                if (val > best_val) {
                    best_val = val;
                    best_k = k;
                }
            }
            
            for (ll k = max(0LL, best_k-2); k <= min(total_gain, best_k+2); k++) {
                best = max(best, dp(l + k, r + (total_gain - k), i+1));
            }
        } else {
            vector<double> ratios = {0, 0.1, 0.25, 0.33, 0.4, 0.45, 0.5, 0.55, 0.6, 0.67, 0.75, 0.9, 1.0};
            ll best_val = 0;
            double best_ratio = 0;
            
            for (double ratio : ratios) {
                ll k = round(ratio * total_gain);
                ll val = dp(l + k, r + (total_gain - k), i+1);
                if (val > best_val) {
                    best_val = val;
                    best_ratio = ratio;
                }
            }
            
            double step = 0.01;
            if (total_gain > 1000) step = 0.05;
            
            for (double r = max(0.0, best_ratio-0.1); r <= min(1.0, best_ratio+0.1); r += step) {
                ll k = round(r * total_gain);
                best = max(best, dp(l + k, r + (total_gain - k), i+1));
            }
        }
        
        return memo[key] = best;
    };
    
    if (n > 15) {
        vector<pair<ll,ll>> dp_table(2, {1, 1});
        int current = 0, next = 1;
        
        for (int i = 0; i < min(5, n); i++) {
            ll l = dp_table[current].first;
            ll r = dp_table[current].second;
            
            ll gain_l = (left[i].first == '+') ? left[i].second : (l * (left[i].second - 1));
            ll gain_r = (right[i].first == '+') ? right[i].second : (r * (right[i].second - 1));
            ll total_gain = gain_l + gain_r;
            
            bool next_l_mult = (i+1 < n && left[i+1].first == 'x');
            bool next_r_mult = (i+1 < n && right[i+1].first == 'x');
            
            if (next_l_mult && !next_r_mult) {
                dp_table[next] = {l + total_gain, r};
            } else if (!next_l_mult && next_r_mult) {
                dp_table[next] = {l, r + total_gain};
            } else if (next_l_mult && next_r_mult) {
                int l_mult = left[i+1].second;
                int r_mult = right[i+1].second;
                double ratio = (double)l_mult / (l_mult + r_mult);
                ll k = round(ratio * total_gain);
                dp_table[next] = {l + k, r + (total_gain - k)};
            } else {
                dp_table[next] = {l + total_gain/2, r + (total_gain - total_gain/2)};
            }
            
            swap(current, next);
        }
        
        return dp(dp_table[current].first, dp_table[current].second, min(5, n));
    }
    
    return dp(1, 1, 0);
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<char,int>> left(n), right(n);
        for (int i = 0; i < n; i++) {
            char op_l, op_r;
            int a_l, a_r;
            cin >> op_l >> a_l >> op_r >> a_r;
            left[i] = {op_l, a_l};
            right[i] = {op_r, a_r};
        }
        
        cout << solve(left, right, n) << ln;
    }

    time();
    return 0;
}