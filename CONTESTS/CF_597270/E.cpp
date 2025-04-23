// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/597270/problem/E

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
    int n; cin >> n;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, vector<int>> pos_a, pos_b;
    for (int i = 0; i < n; i++) {
        pos_a[a[i]].push_back(i);
        pos_b[b[i]].push_back(i);
    }

    for (const auto& [val, pos] : pos_a) {
        if (pos_b[val].size() != pos.size()) {
            cout << "NO" << ln;
            return;
        }
    }

    map<int, int> idx_a, idx_b;
    for (int i = 0; i < n; i++) {
        idx_a[a[i]] = i;
        idx_b[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] != a[j] && a[i] != b[j] && a[j] != b[i]) {
                if ((i < j && idx_b[a[i]] > idx_b[a[j]]) || 
                    (i > j && idx_b[a[i]] < idx_b[a[j]])) {
                    cout << "NO" << ln;
                    return;
                }
            }
        }
    }
    
    cout << "YES" << ln;
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