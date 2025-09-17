#include <bits/stdc++.h>
using namespace std;

#define NAME "KNAPSACK"
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

struct Query {
    int l, r, t;
};

int n, q;
vector<int> weights, vals;
vector<Query> Q;
ll res = 0;
int Cmax = 0;

void recursive(int L, int R, const vector<int>& ids) {
    if (ids.empty()) 
        return;
    
    if (L == R) {
        int w = weights[L], v = vals[L];
        for (int id : ids) {
            int t = Q[id].t;
            if (w <= t) res += v;
        }
        return;
    }

    int M = (L + R) >> 1;
    vector<int> left, right, cross;
    left.reserve(ids.size());
    right.reserve(ids.size());
    cross.reserve(ids.size());

    for (int id : ids) {
        const auto& qu = Q[id];
        if (qu.r <= M) 
            left.push_back(id);
        else if (qu.l > M) 
            right.push_back(id);
        else 
            cross.push_back(id);
    }

    if (!cross.empty()) {
        int leftLen = M - L + 1;
        vector<vector<int>> dpL(leftLen, vector<int>(Cmax + 1, 0));
        vector<int> dp(Cmax + 1, 0);

        for (int i = M; i >= L; --i) {
            int w = weights[i], v = vals[i];

            for (int c = Cmax; c >= w; --c)
                dp[c] = max(dp[c], dp[c - w] + v);

            dpL[i - L] = dp;
        }

        int rightLen = R - M;
        vector<vector<int>> dpR(rightLen, vector<int>(Cmax + 1, 0));

        fill(dp.begin(), dp.end(), 0);

        for (int j = M + 1; j <= R; ++j) {
            int w = weights[j], v = vals[j];

            for (int c = Cmax; c >= w; --c)
                dp[c] = max(dp[c], dp[c - w] + v);

            dpR[j - (M + 1)] = dp;
        }

        for (int id : cross) {
            const auto& qu = Q[id];
            const vector<int>& A = dpL[qu.l - L];
            const vector<int>& B = dpR[qu.r - (M + 1)];

            int t = qu.t;
            int best = 0;

            for (int k = 0; k <= t; ++k)
                best = max(best, A[k] + B[t - k]);

            res += best;
        }
    }

    recursive(L, M, left);
    recursive(M + 1, R, right);
}

void solve() {
    cin >> n;
    weights.assign(n + 1, 0);
    vals.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> weights[i] >> vals[i];

    cin >> q;
    Q.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> Q[i].l >> Q[i].r >> Q[i].t;
        Cmax = max(Cmax, Q[i].t);
    }

    vector<int> all(q);
    iota(all.begin(), all.end(), 0);
    recursive(1, n, all);

    cout << res << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    while (t--) {
        solve();
    }

    time();
    return 0;
}