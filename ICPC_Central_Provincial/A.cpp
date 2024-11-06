#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
#define ln "\n"

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;  // Infinity for large values

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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();
   
    int n;
    ll W, H;
    cin >> n >> W >> H;
   
    vector<ll> w(n), v(n);
    ll sum_val = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        sum_val += v[i];  
    }
   
    vector<ll> dp(sum_val + 1, INF);
    dp[0] = 0;  
   
    for(int i = 0; i < n; i++) {
        for(ll j = sum_val; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
   
    ll res = 0;
   
    for(int i = 0; i <= sum_val; i++) {
        if (dp[i] <= W) {
            res = max(res, (ll)i);
        }
    }
   
    for(int i = 0; i < n; i++) {
        if(w[i] > H) continue;
        
        vector<ll> tmp(sum_val + 1, INF);
        tmp[0] = 0;
        
        for(int j = 0; j < n; j++) {
            if(j == i) continue; 
            for(ll value = sum_val; value >= v[j]; value--) {
                tmp[value] = min(tmp[value], tmp[value - v[j]] + w[j]);
            }
        }
        
        for(int j = 0; j <= sum_val; j++) {
            if(tmp[j] <= W) {
                res = max(res, j + v[i]);
            }
        }
    }
   
    cout << res;
   
    time();
    return 0;
}
