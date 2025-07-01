// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_matbiendoi"
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
    vector<int> a(n), b(n);
    map<int, int> mp;
    bool possible = true;

    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (a[i] != b[i])
            mp[b[i]]++;
    }

    int m; cin >> m;
    vector<int> d(m);
    map<int, int> mp2;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        mp2[d[i]]++;
    }

    for (auto const& [val, cnt] : mp) {
        if (mp2[val] < cnt) {
            possible = false;
            break;
        }
    }

    if (possible) {
        int last = d[m - 1];
        if (mp.find(last) == mp.end()) {
            bool found = false;
            for(int i = 0; i < n; ++i) {
                if (b[i] == last) {
                    found = true;
                    break;
                }
            }
            if (!found)
                possible = false;
        }
    }

    if (possible)
        cout << "YES" << ln;
    else
        cout << "NO" << ln;
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