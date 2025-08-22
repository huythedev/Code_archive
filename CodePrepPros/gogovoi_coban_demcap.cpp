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
    int n, k; cin >> n >> k;
    unordered_map<int, int> freq;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    ll res = 0;
    set<int> st;
    for (auto &p : freq) {
        int x = p.first;
        int y = k - x;

        if (freq.count(y)) {
            if (x < y) {
                res += 1LL * freq[x] * freq[y];
            } 
            else if (x == y) {
                res += 1LL * freq[x] * (freq[x] - 1) / 2;
            }
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