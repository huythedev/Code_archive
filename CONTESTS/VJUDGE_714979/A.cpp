// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/A
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

signed main() {
    fastio();
    docfile();

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    for (int k = 0; k < m; ++k) {
        int q; cin >> q;

        auto it = lower_bound(a.begin(), a.end(), q);

        int res = -1;
        if (it != a.end() && *it == q) {
            res = distance(a.begin(), it) + 1;
        }

        if (k > 0) {
            cout << " ";
        }
        cout << res;
    }

    time();
    return 0;
}