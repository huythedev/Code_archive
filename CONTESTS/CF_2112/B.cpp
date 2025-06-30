// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) <= 1) {
            cout << 0 << ln;
            return;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int minA = min(a[i], a[i + 1]), maxA = max(a[i], a[i + 1]);

        if (i - 1 >= 0) {
            if (maxA >= a[i - 1] - 1 && minA <= a[i - 1] + 1) {
                cout << 1 << ln;
                return;
            }
        }

        if (i + 2 < n) {
            if (maxA >= a[i + 2] - 1 && minA <= a[i + 2] + 1) {
                cout << 1 << ln;
                return;
            }
        }
    }

    cout << -1 << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}