// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }

    vector<int> h1 = {0}, h2 = {0};
    int min_height = 0, max_height = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int tmp, tmp2;

        if (d[i] == 0) {
            tmp = min_height + 0;
            tmp2 = max_height + 0;
        } else if (d[i] == 1) {
            tmp = min_height + 1;
            tmp2 = max_height + 1;
        } else {
            tmp = min_height + 0;
            tmp2 = max_height + 1;
        }

        min_height = max(tmp, vec[i].first);
        max_height = min(tmp2, vec[i].second);

        if (min_height > max_height) {
            ok = false;
            break;
        }

        h1.push_back(min_height);
        h2.push_back(max_height);
    }

    if (!ok) {
        cout << -1 << ln;
        return;
    }

    vector<int> res = d;
    int h = h1.back();
    for (int i = n - 1; i >= 0; --i) {
        int di;
        if (d[i] != -1) {
            di = d[i];
        } else {
            if (h1[i] <= h && h <= h2[i]) {
                di = 0;
            } else {
                di = 1;
            }
            res[i] = di;
        }

        int prev_height = h - di;
        h = prev_height;
    }

    for (int val : res) {
        cout << val << " ";
    }
    cout << ln;
}

signed main() {
    docfile();
    fastio();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}