// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/604613/problem/C
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

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> col(n);
    for (int i = 0; i < n; ++i) {
        col[i] = s[i] - 'A';
    }
    vector<vector<int>> dp(n, vector<int>(k));
    vector<vector<int>> parent(n, vector<int>(k));
    for (int c = 0; c < k; ++c) {
        dp[0][c] = (c == col[0] ? 0 : 1);
        parent[0][c] = -1;
    }

    for (int i = 1; i < n; ++i) {
        for (int c = 0; c < k; ++c) {
            int min_val = INT_MAX;
            int min_c = -1;
            for (int c_prev = 0; c_prev < k; ++c_prev) {
                if (c_prev != c && dp[i - 1][c_prev] < min_val) {
                    min_val = dp[i - 1][c_prev];
                    min_c = c_prev;
                }
            }
            dp[i][c] = min_val + (col[i] == c ? 0 : 1);
            parent[i][c] = min_c;
        }
    }

    int min_dp = INT_MAX;
    int min_c = -1;
    for (int c = 0; c < k; ++c) {
        if (dp[n - 1][c] < min_dp) {
            min_dp = dp[n - 1][c];
            min_c = c;
        }
    }

    vector<int> chosen(n);
    chosen[n - 1] = min_c;
    for (int i = n - 1; i >= 1; --i) {
        chosen[i - 1] = parent[i][chosen[i]];
    }
    cout << min_dp << ln;
    for (int i = 0; i < n; ++i) {
        cout << (char)(chosen[i] + 'A');
    }
    cout << ln;

    time();
    return 0;
}