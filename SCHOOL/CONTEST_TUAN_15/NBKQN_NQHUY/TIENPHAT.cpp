// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TIENPHAT"
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

signed main() {
    fastio();
    docfile();

    ll n; cin >> n;
    vector<pair<ll, ll>> marbles(n);
    for (pair<ll, ll> p : marbles) {
        cin >> p.first >> p.second;
    }

    sort(marbles.begin(), marbles.end());

    vector<ll> x(n), c(n);
    for (int i = 0; i < n; ++i) {
        x[i] = marbles[i].first;
        c[i] = marbles[i].second;
    }

    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + x[i - 1];
    }

    vector<ll> dp(n);
    dp[0] = c[0];
    for (int i = 1; i < n; ++i) {
        ll min_val = LLONG_MAX;
        for (int j = 0; j < i; ++j) {
            ll roll_cost = (s[i] - s[j + 1]) - (i - j - 1LL) * x[j];
            ll temp = dp[j] + roll_cost;
            min_val = min(min_val, temp);
        }
        dp[i] = c[i] + min_val;
    }

    ll ans = LLONG_MAX;
    for (int k = 0; k < n; ++k) {
        ll roll_cost = (s[n] - s[k + 1]) - (n - k - 1LL) * x[k];
        ll total_cost = dp[k] + roll_cost;
        ans = min(ans, total_cost);
    }
    
    cout << ans << ln;

    time();
    return 0;
}
