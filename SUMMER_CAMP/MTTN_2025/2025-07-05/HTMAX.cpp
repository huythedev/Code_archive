// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "HTMAX"
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

const int maxn = 1e5 + 5;

int n;
ll a[maxn + 5], dp[maxn + 5];
vector<int> res;

void recur(int i, ll best) {
    if (i >= n || best == 0) 
        return;
    if (dp[i + 2] + a[i] == best) {
        res.push_back(i);
        recur(i + 2, best - a[i]);
    } 
    else {
        recur(i + 1, best);
    }
}


void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    dp[n] = dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; --i) 
        dp[i] = max(dp[i + 2] + a[i], dp[i + 1]);

    recur(0, dp[0]);

    cout << dp[0] << ln;
    cout << res.size() << ln;
    for (int i : res) 
        cout << i + 1 << " ";

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
