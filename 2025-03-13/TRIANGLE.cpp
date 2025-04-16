// Author: huythedev (https://huythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "TRIANGLE"
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

int m, n, k;

signed main() {
    fastio();
    docfile();

    cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> row_prefix(m, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row_prefix[i][j + 1] = row_prefix[i][j] + a[i][j];
        }
    }

    ll max_sum = LLONG_MIN;
    for (int i = 0; i <= m - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            ll sum = 0;
            for (int r = 0; r < k; r++) {
                sum += row_prefix[i + r][j + r + 1] - row_prefix[i + r][j];
            }
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum;

    time();
    return 0;
}