// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/D
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

const ll INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<pair<int, ll>>> graph(n + 1);
    for(int i = 0; i < m; i++) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        graph[s].push_back({t, w});
    }

    ll l = 0, r = 1e18;
    while(l < r) {
        ll mid = (l + r) / 2;
        vector<ll> dp(n + 1, INF);
        for(int i = n - 1; i >= 1; i--) {
            for(auto [u, w] : graph[i]) {
                if(w <= mid) {
                    if(u == n) {
                        dp[i] = min(dp[i], w);
                    } else if(dp[u] != INF) {
                        dp[i] = min(dp[i], max(w, dp[u] - b[u]));
                    }
                }
            }
        }

        if(dp[1] <= b[1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    vector<ll> dp(n + 1, INF);
    for(int i = n - 1; i >= 1; i--) {
        for(auto [u, w] : graph[i]) {
            if(w <= l) {
                if(u == n) {
                    dp[i] = min(dp[i], w);
                } else if(dp[u] != INF) {
                    dp[i] = min(dp[i], max(w, dp[u] - b[u]));
                }
            }
        }
    }
    
    if(dp[1] <= b[1]) {
        cout << l << ln;
    } else {
        cout << -1 << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}