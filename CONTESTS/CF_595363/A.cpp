// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/595363/problem/A

#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

const int maxn = 1e3 + 5;

int n, m;
vector<vector<int>> a(maxn, vector<int>(maxn));

signed main() {
    fastio();
    docfile();

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    
    vector<pair<int, int>> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        int val1 = 0, val2 = 0;
        
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] > 0) val1 += a[i][j];
            else if (a[i][j] < 0) val2 += -a[i][j];
        }
        
        vec[i] = {val1, val2};
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            res = max(res, vec[i].first + (i != j ? vec[j].first : 0));
            res = max(res, vec[i].second + (i != j ? vec[j].second : 0));
            
            if (i != j) res = max(res, vec[i].first + vec[j].second);
            if (i != j) res = max(res, vec[i].second + vec[j].first);
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}