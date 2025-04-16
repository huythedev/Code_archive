// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/F
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

    int R, G, B;
    cin >> R >> G >> B;
    
    vector<int> red(R), green(G), blue(B);
    
    for (int i = 0; i < R; i++) cin >> red[i];
    for (int i = 0; i < G; i++) cin >> green[i];
    for (int i = 0; i < B; i++) cin >> blue[i];
    
    sort (red.rbegin(), red.rend());
    sort (green.rbegin(), green.rend());
    sort (blue.rbegin(), blue.rend());
    
    vector<vector<vector<int>>> dp (R + 1, vector<vector<int>>(G + 1, vector<int>(B + 1, 0)));
    
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k <= B; k++) {
                if (i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                
                if (i > 0 && j > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + red[i-1] * green[j-1]);
                
                if (i > 0 && k > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + red[i-1] * blue[k-1]);
                
                if (j > 0 && k > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + green[j-1] * blue[k-1]);
            }
        }
    }
    
    cout << dp[R][G][B] << ln;
    
    time();
    return 0;
}