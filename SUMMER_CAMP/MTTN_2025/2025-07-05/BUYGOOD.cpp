// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BUYGOOD"
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < m; ++i) {
        ll s, p, w; cin >> s >> p >> w;

        if (s == 0) {
            continue;
        }

        vector<ll> dp_prev = dp;
        deque<int> dq;

        for (int j = 1; j <= n; ++j) {
            ll val = (dp_prev[j - 1] == INF) ? INF : (dp_prev[j - 1] - (ll)(j - 1) * p);
            
            while (!dq.empty()) {
                int pre_idx = dq.back();
                ll val2 = (dp_prev[pre_idx] == INF) ? INF : (dp_prev[pre_idx] - (ll)pre_idx * p);
                if (val2 >= val) {
                    dq.pop_back();
                } 
                else {
                    break;
                }
            }

            dq.push_back(j - 1);

            if (dq.front() < j - s) {
                dq.pop_front();
            }

            int best_idx = dq.front();
            
            if (dp_prev[best_idx] != INF) {
                ll min_Vx = dp_prev[best_idx] - (ll)best_idx * p;
                ll new_cost = w + (ll)j * p + min_Vx;

                dp[j] = min(dp[j], new_cost);
            }
        }
    }

    cout << dp[n] << ln;
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
