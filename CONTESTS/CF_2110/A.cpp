// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/A
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
    vector<bool> val(51, false);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        val[a[i]] = true;
    }

    if (n == 1) {
        cout << 0 << ln;
        return;
    }

    sort(a.begin(), a.end());

    if ((a[0] + a[n - 1]) % 2 == 0) {
        cout << 0 << ln;
        return;
    }

    int res = n - 1; 

    for (int i = 1; i <= 50; ++i) {
        for (int j = i; j <= 50; ++j) {
            if ((i + j) % 2 != 0) { 
                continue;
            }
            if (!val[i] || !val[j]) {
                continue;
            }
            int ops = 0;
            auto tmp = lower_bound(a.begin(), a.end(), i);
            ops += distance(a.begin(), tmp);
            auto tmp2 = upper_bound(a.begin(), a.end(), j);
            ops += distance(tmp2, a.end());
            res = min(res, ops);
        }
    }

    cout << res << ln;
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