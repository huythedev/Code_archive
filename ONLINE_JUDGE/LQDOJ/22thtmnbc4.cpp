// Author: Perry (https://perrythedev.com)
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

using pll = pair<ll, ll>;

class FenwickTree {
    private:
        vector<pll> tree; 
        int n;
    public:
        FenwickTree(int size) : n(size), tree(size + 1, {0, 0}) {}
        void add(int idx, ll val) {
            idx++; 
            while (idx <= n) {
                tree[idx].first += 1;
                tree[idx].second += val;
                idx += idx & -idx;
            }
        }
        pll query(int idx) {
            idx++; 
            ll cnt = 0, sum = 0;
            while (idx > 0) {
                cnt += tree[idx].first;
                sum += tree[idx].second;
                idx -= idx & -idx;
            }
            return {cnt, sum};
        }
    };
    
    pll compute_N_T(ll S, const vector<ll>& p, const vector<ll>& sorted_p, const vector<int>& rank, int X, int n) {
        int m = sorted_p.size();
        FenwickTree ft(m);
        ll N = 0, T = 0;
        for (int r = X; r <= n; r++) {
            ft.add(rank[r - X], p[r - X]);
            ll thresh = p[r] - S;
            auto it = upper_bound(sorted_p.begin(), sorted_p.end(), thresh);
            int idx = (it == sorted_p.begin()) ? -1 : (it - sorted_p.begin() - 1);
            if (idx >= 0) {
                auto [cnt, sum_p] = ft.query(idx);
                N += cnt;
                T += p[r] * cnt - sum_p;
            }
        }
        return {N, T};
    }

signed main() {
    fastio();
    docfile();

    int n, X;
    ll k;
    cin >> n >> k >> X;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    vector<ll> sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end());
    sorted_p.erase(unique(sorted_p.begin(), sorted_p.end()), sorted_p.end());

    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++) {
        rank[i] = lower_bound(sorted_p.begin(), sorted_p.end(), p[i]) - sorted_p.begin();
    }

    ll left = -1e5 * n, right = 1e5 * n;
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;
        ll N = compute_N_T(mid, p, sorted_p, rank, X, n).first;
        if (N >= k) left = mid;
        else right = mid - 1;
    }
    ll S = left;

    auto [M, T] = compute_N_T(S + 1, p, sorted_p, rank, X, n);
    ll ans = T + S * (k - M);
    cout << ans << endl;

    time();
    return 0;
}