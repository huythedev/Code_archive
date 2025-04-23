// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/597270/problem/B

#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

    int n, c;
    cin >> n >> c;
    
    vector<int> heights(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    
    vector<ll> prev(101, LLONG_MAX);
    vector<ll> curr(101, LLONG_MAX);
    
    for (int i = heights[1]; i <= 100; i++) {
        prev[i] = 1LL * (i - heights[1]) * (i - heights[1]);
    }
    
    for (int i = 2; i <= n; i++) {
        fill(curr.begin(), curr.end(), LLONG_MAX);
        
        for (int j = heights[i]; j <= 100; j++) {
            ll tmp = 1LL * (j - heights[i]) * (j - heights[i]);
            
            ll tmp2 = LLONG_MAX;
            for (int prev_h = heights[i-1]; prev_h <= 100; prev_h++) {
                if (prev[prev_h] != LLONG_MAX) {
                    ll wire_cost = 1LL * c * abs(j - prev_h);
                    tmp2 = min(tmp2, prev[prev_h] + wire_cost);
                }
            }
            
            if (tmp2 != LLONG_MAX) {
                curr[j] = tmp + tmp2;
            }
        }
        
        prev.swap(curr);
    }
    
    ll res = LLONG_MAX;
    for (int i = heights[n]; i <= 100; i++) {
        res = min(res, prev[i]);
    }
    
    cout << res << ln;

    time();
    return 0;
}