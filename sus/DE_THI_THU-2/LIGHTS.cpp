// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "LIGHTS"
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

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> segments; 
    for (int i = 0; i < N; ) {
        if (a[i] == 1) {
            int left = i;
            while (i < N && a[i] == 1) i++;
            segments.push_back({left, i - 1});
        } else {
            i++;
        }
    }
    int m = segments.size();

    if (m == 0) {
        cout << 0 << ln;
        return;
    }

    vector<int> pre(N + 1, 0);
    for (int j = 0; j < N; j++) {
        pre[j + 1] = pre[j] + (1 - a[j]);
    }

    vector<int> dp(m + 1, 1e9); 
    dp[0] = 0; 

    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= i; k++) {
            int l_k = segments[k - 1].first;
            int r_i = segments[i - 1].second;
            int length = r_i - l_k + 1;
            if (length >= 4) {
                int cost = pre[r_i + 1] - pre[l_k];
                if (k == 1) {
                    dp[i] = min(dp[i], cost);
                } else {
                    dp[i] = min(dp[i], dp[k - 1] + cost);
                }
            }
        }
    }

    cout << dp[m] << ln;
}

signed main() {
    fastio();
    docfile();

    solve();

    time();
    return 0;
}