// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/F
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

const int INF = 1e9;
const int MOD = 998244353;

int solve(vector<int>& a, int n) {
    map<int, int> increasing, decreasing;
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int maxLIS = 0, maxLDS = 0;
        
        auto it1 = increasing.lower_bound(x);
        if (it1 != increasing.begin()) {
            --it1;
            maxLIS = it1->second;
        }
        
        auto it2 = decreasing.upper_bound(x);
        if (it2 != decreasing.end()) {
            maxLDS = it2->second;
        }
        dp[i] = max(maxLIS + 1, maxLDS + 1);
        increasing[x] = max(increasing[x], dp[i]);
        decreasing[x] = max(decreasing[x], dp[i]);
    }
    
    return *max_element(dp.begin(), dp.end());
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, n) << ln;
    }

    time();
    return 0;
}