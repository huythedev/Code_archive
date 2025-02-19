// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6treasure
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6treasure"
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

struct item {
    ll w, v, b, k;
};

int n;
ll w;
vector<item> vec;

ll calc(int i, ll x) {
    if (x == 0) 
        return 0;
    return vec[i].v * x + vec[i].b - vec[i].k * (x * x);
}

void solve() {
    vector<ll> dp(w + 1, LLONG_MIN);  
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        vector<ll> tmp = dp;
        
        for (ll j = 0; j <= w; j++) {
            if (dp[j] == LLONG_MIN) 
                continue;
            
            ll tmp2 = w - j;
            if (tmp2 < vec[i].w) 
                continue;
            
            ll tmp3;
            if (vec[i].k == 0) {
                tmp3 = tmp2 / vec[i].w;
            } 
            else {
                tmp3 = vec[i].v / (2 * vec[i].k);
                tmp3 = min(tmp3, tmp2 / vec[i].w);
            }
            
            for (ll x = max(0LL, tmp3 - 1); x <= min(tmp2 / vec[i].w, tmp3 + 1); x++) {
                ll tmp4 = j + x * vec[i].w;
                if (tmp4 > w) continue; 
                ll val = calc(i, x);
                tmp[tmp4] = max(tmp[tmp4], dp[j] + val);
            }
        }
        dp = tmp;
    }
    
    cout << *max_element(dp.begin(), dp.end());
}

int main() {
    fastio();
    docfile();
    
    cin >> n >> w;
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].w >> vec[i].v >> vec[i].b >> vec[i].k;
    }
    
    solve();
    
    time();
    return 0;
}