// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1512/A

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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int res = -1;
        if (a[0] != a[1] && a[0] != a[2]) {
            res = 1;
        } else {
            for (int i = 1; i < n; ++i) {
                if (a[i] != a[0]) {
                    res = i + 1;
                    break;
                }
            }
        }
        cout << res << ln;
    }

    time();
    return 0;
}