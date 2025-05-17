// Author: huythedev
// Problem Link: https://lqdoj.edu.vn/problem/23qnab4
#include <bits/stdc++.h>
using namespace std;

#define NAME "BOATCAR"
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
    
    int n, q; cin >> n >> q;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; ++i) {
        int k, u; cin >> k >> u;
        items.emplace_back(k, u);
    }

    vector<ll> dp(q + 1, LLONG_MIN);
    dp[0] = 0;
    for (const auto& i : items) {
        for (int j = q; j >= i.first; --j) {
            if (dp[j - i.first] != LLONG_MIN) {
                dp[j] = max(dp[j], dp[j - i.first] + i.second);
            }
        }
    }
    ll sum = *max_element(dp.begin(), dp.end());

    vector<ll> dp2(q + 1, 0);
    for (int j = 1; j <= q; ++j) {
        for (const auto& i : items) {
            if (j >= i.first) {
                dp2[j] = max(dp2[j], dp2[j - i.first] + i.second);
            }
        }
    }
    ll sum2 = *max_element(dp2.begin(), dp2.end());

    cout << sum << '\n' << sum2 << '\n' << 5 * (sum2 - sum) << '\n';

    time();
    return 0;
}