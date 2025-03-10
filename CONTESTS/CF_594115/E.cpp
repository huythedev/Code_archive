// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/E
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

string st;

signed main() {
    fastio();
    docfile();

    cin >> st;
    
    int n = st.length();
    vector<vector<int>> dp(n + 1, vector<int>(4, INT_MIN));
    dp[0][0] = 0;  
    
    for (int i = 1; i <= n; ++i) {
        char curr = st[i - 1];
        
        for (int j = 0; j <= 3; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
        
        if (curr == 'W') {
            dp[i][1] = max(dp[i][1], dp[i-1][0] + 2);
            dp[i][2] = max(dp[i][2], dp[i-1][1] + 2);
            dp[i][3] = max(dp[i][3], dp[i-1][2] + 3);
            dp[i][3] = max(dp[i][3], dp[i-1][3] + 3);
        } 
        else {
            int points = (curr == 'D') ? 1 : 0;
            for (int j = 0; j <= 3; ++j) {
                dp[i][0] = max(dp[i][0], dp[i-1][j] + points);
            }
        }
    }
    
    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << ln;

    time();
    return 0;
}