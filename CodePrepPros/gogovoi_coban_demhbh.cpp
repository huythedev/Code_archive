// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_coban_demhbh"
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
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int mid_x = points[i].first + points[j].first;
            int mid_y = points[i].second + points[j].second;
            mp[{mid_x, mid_y}]++;
        }
    }
    
    ll res = 0;
    for (auto& i : mp) {
        int k = i.second;
        if (k >= 2) {
            res += (ll)k * (k - 1) / 2;
        }
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