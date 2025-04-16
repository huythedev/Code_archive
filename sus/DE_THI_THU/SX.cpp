// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "SX"
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

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<pair<int, int>> ops;
    for (int k = 0; k < n - 1; k++) {
        int m = k;
        for (int i = k; i < n; i++) {
            if (a[i] < a[m]) m = i;
        }
        if (m != k) {
            reverse(a.begin() + k, a.begin() + m + 1);
            ops.push_back({k + 1, m + 1});
        }
    }

    cout << ops.size() << ln;
    for (pair<int, int> op : ops) {
        cout << op.first << " " << op.second << ln;
    }

    time();
    return 0;
}