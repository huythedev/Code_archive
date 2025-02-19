// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/palindoi
#include <bits/stdc++.h>
using namespace std;

#define NAME "palindoi"
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

bool isPalin(string& s, int start, int len) {
    for(int i = 0; i < len/2; i++) {
        if(s[start + i] != s[start + len - 1 - i]) 
            return false;
    }
    return true;
}

void solve() {
    int n; string s;
    cin >> n >> s;
    
    vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
    
    for(int i = 0; i < n; i++) {
        dp[i][1] = true;
        if(i < n-1) dp[i][2] = (s[i] == s[i+1]);
    }
    
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            dp[i][len] = (s[i] == s[i+len-1]) && dp[i+1][len-2];
        }
    }
    
    ll ans = 0;
    for(int len = 2; len <= n; len += 2) {
        int half = len/2;
        for(int i = 0; i + len <= n; i++) {
            if(dp[i][half] && dp[i+half][half]) ans++;
        }
    }
    
    cout << ans;
}

int main() {
    fastio();
    docfile();
    
    solve();

    time();
    return 0;
}