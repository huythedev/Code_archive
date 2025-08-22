// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI1"
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

const ll MOD = 20030101;

pair<int, ll> get_lcs(const string& s, const string& t) {
    int n = s.sz;
    int m = t.sz;
    
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } 
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    
    vector<vector<ll>> D(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        D[i][0] = 1;
    }

    for (int j = 0; j <= m; ++j) {
        D[0][j] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                D[i][j] = D[i - 1][j - 1];
            } 
            else {
                ll val = 0;
                if (L[i - 1][j] == L[i][j]) {
                    val = (val + D[i - 1][j]) % MOD;
                }

                if (L[i][j - 1] == L[i][j]) {
                    val = (val + D[i][j - 1]) % MOD;
                }

                if (L[i - 1][j - 1] == L[i][j]) {
                    val = (val - D[i - 1][j - 1] + MOD) % MOD;
                }

                D[i][j] = val;
            }
        }
    }
    
    if (L[n][m] == 0) {
        return {0, 0};
    }
    
    return {L[n][m], D[n][m]};
}

void solve() {
    string s, t;
    cin >> s >> t;

    pair<int, ll> res = get_lcs(s, t);
    cout << res.first << " " << res.second << ln;
}

signed main() {
    fastio();
    docfile();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
