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

const ll INF = 1e18;

ll calc(vector<int> a) {
    int n = a.size();
    
    if (n == 0) 
        return 0;
    if (n % 2 != 0 && n % 3 != 0 && n < 5) 
        return INF;

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i >= 2) {
            if (dp[i - 2] != INF)
                dp[i] = min(dp[i], dp[i - 2] + abs(a[i - 1] - a[i - 2]));
        }
        if (i >= 3) {
            if (dp[i - 3] != INF) {
                ll mx = max({a[i - 1], a[i - 2], a[i - 3]});
                ll mn = min({a[i - 1], a[i - 2], a[i - 3]});
                dp[i] = min(dp[i], dp[i - 3] + (mx - mn));
            }
        }
    }

    return dp[n];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> a2 = a;
    ll ans = calc(a2);

    rotate(a2.begin(), a2.begin() + 1, a2.end());
    ans = min(ans, calc(a2));
    
    rotate(a2.begin(), a2.begin() + 1, a2.end());
    ans = min(ans, calc(a2));

    cout << ans << ln;
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