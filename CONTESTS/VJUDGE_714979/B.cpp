// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/B
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

signed main() {
    fastio();
    docfile();

    int n; int c; cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll res = 0;

    for (int i : a) {
        int tmp = i - c;

        auto lo = lower_bound(a.begin(), a.end(), tmp);
        auto hi = upper_bound(a.begin(), a.end(), tmp);
        
        res += distance(lo, hi);
    }

    cout << res << ln;

    time();
    return 0;
}