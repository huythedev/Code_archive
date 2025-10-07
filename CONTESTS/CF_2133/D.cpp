// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> h[i];

    vector<int> cost(n + 2, 0);
    for (int i = 1; i <= n; i++) 
        cost[i] = max(0, h[i] - 1);

    vector<ll> prefixSum(n + 2, 0);
    for (int i = 1; i <= n; i++) 
        prefixSum[i] = prefixSum[i - 1] + cost[i];
    
    vector<ll> dp(n + 1, 0);
    ll tmp = 4e18;
    for (int i = 1; i <= n; i++) {
        ll tmp2 = dp[i - 1] + h[i] - prefixSum[i];
        dp[i] = prefixSum[i] + min(tmp, tmp2);

        if (i < n) {
            ll minDamage = min(i - 1, cost[i + 1]);
            ll Cost = dp[i - 1] + h[i] - minDamage - prefixSum[i];
            tmp = min(tmp, Cost);
        }
    }

    cout << dp[n] << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}