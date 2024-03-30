#include <bits/stdc++.h>
using namespace std;

#define NAME "MARKET"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME ".inp")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
}

ll solve(ll n, ll M, vector<pair<ll, ll>> &items) {
    vector<vector<ll>> dp(n + 1, vector<ll>(M + 1, 0));

    for (ll i = 1; i <= n; ++i) {
        for (ll w = 0; w <= M; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (w >= items[i - 1].first) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - items[i - 1].first] + items[i - 1].second);
            }
        }
    }

    return dp[n][M];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    docfile();

    vector<pair<ll, ll>> items;
    ll n, M;
    cin >> n >> M;
    items.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    ll result = solve(n, M, items);

    if (result > 0) {
        cout << result << ln;
    } else {
        cout << -1 << ln;
    }

    return 0;
}
