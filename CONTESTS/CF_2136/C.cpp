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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<vector<int>> pos(n + 1);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        int ai = a[i];

        int cnt = (int)pos[ai].size() + 1;
        int tmp = -1;

        if (cnt >= ai) {
            int idx = cnt - ai, L;
            if (idx >= (int)pos[ai].size())
                L = i;
            else
                L = pos[ai][idx];
            
            int prev = (L - 1 >= 0 ? dp[L - 1] : 0);
            tmp = prev + ai;
        }

        dp[i] = (i > 0 ? dp[i - 1] : 0);

        if (tmp > dp[i])
            dp[i] = tmp;
        
        pos[ai].push_back(i);
    }

    cout << dp[n - 1] << ln;
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