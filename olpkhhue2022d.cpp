#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> range(n);
        for (int i = 0; i < n; ++i) {
            cin >> range[i].first >> range[i].second;
        }

        ll res = 0;
        vector<ll> dp(n, 0);
        
        for (ll x = range[0].first; x <= range[0].second; ++x) {
            dp[0] = 1;
            for (int i = 1; i < n; ++i) {
                ll cnt = 0;
                for (ll y = range[i].first; y <= range[i].second; ++y) {
                    if (lcm(x, y) == max(x, y)) {
                        cnt = (cnt + dp[i - 1]) % MOD;
                    }
                }
                dp[i] = cnt;
            }
            res = (res + dp[n - 1]) % MOD;
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
