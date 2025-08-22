// Author: huythedev
// Problem Link: 
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    sort(a.begin(), a.end());
    multiset<ll> mst;

    ll sum = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) {
        while (i < j && a[i] <= a[j] - k) {
            mst.insert(a[i]);
            ++i;
        }
        
        if (!mst.empty()) {
            auto it = prev(mst.end());
            sum += *it;
            mst.erase(it);
        }
    }

    cout << (total - sum) << ln;
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