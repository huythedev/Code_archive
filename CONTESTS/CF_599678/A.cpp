// Author: Perry
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/599678/problem/A
// davul
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

    string s;
    cin >> s;
    
    int n = s.length();
    
    if (n == 0) {
        cout << "0 1" << ln;
        time();
        return 0;
    }
    
    vector<int> dp(n, 0);
    
    int maxLen = 0;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') 
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') 
                dp[i] = dp[i-1] + 2 + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0);
            maxLen = max(maxLen, dp[i]);
        }
    }
    
    int cnt = 0;
    
    if (maxLen == 0) {
        cout << "0 1" << ln;
        time();
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) {
            cnt++;
        }
    }
    
    cout << maxLen << " " << cnt << ln;

    time();
    return 0;
}