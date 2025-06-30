// Author: huythedev
// Problem Link: https://codeforces.com/group/GmBcp47v69/contest/441327/problem/K
#include <bits/stdc++.h>
using namespace std;

#define NAME "K"
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> increase(n, 1), decrease(n, 1);
    for (int i = 0; i < n; ++i) {
        int x = -1;
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) {
                if (increase[i] < increase[j] + 1) {
                    increase[i] = increase[j] + 1;
                    x = j;
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int x = -1;
        for (int j = n - 1; j > i; --j) {
            if (a[i] > a[j]) {
                if (decrease[i] < decrease[j] + 1) {
                    decrease[i] = decrease[j] + 1;
                    x = j;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, min(increase[i], decrease[i]) * 2 - 1);
    }

    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}