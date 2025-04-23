// Author: huythedev (https://huythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc2

#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc2"
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

int main() {
    fastio();
    docfile();

    int n, g;
    cin >> n >> g;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> richness(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        unordered_set<int> provinces;
        for (int j = i; j < n; j++) {
            provinces.insert(c[j]);
            richness[i][j] = provinces.size();
        }
    }

    vector<vector<int>> dp(n, vector<int>(g + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][1] = richness[0][i];
    }

    for (int j = 2; j <= g; j++) {
        for (int i = j - 1; i < n; i++) { 
            for (int k = j - 2; k < i; k++) { 
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + richness[k + 1][i]);
            }
        }
    }

    cout << dp[n - 1][g] << ln;

    time();
    return 0;
}
