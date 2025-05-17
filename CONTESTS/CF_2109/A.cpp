// Author: huythedev
// Problem Link: https://codeforces.com/contest/2109/problem/A
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    bool all_ones = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            all_ones = false;
        }
    }

    bool tmp = false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 0 && a[i + 1] == 0) {
            tmp = true;
            break;
        }
    }

    if (tmp) {
        cout << "YES" << ln;
        return;
    }

    if (all_ones) {
        cout << "YES" << ln;
        return;
    }

    cout << "NO" << ln;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}