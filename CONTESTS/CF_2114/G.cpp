// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "G"
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bitset<1000001> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<int> possible_s;
        int val = a[i];
        for (int m = 0; (1 << m) <= val && (1 << m) <= k; m++) {
            if (val % (1 << m) == 0) {
                possible_s.push_back(1 << m);
            }
        }

        bitset<1000001> new_dp;
        for (int s : possible_s) {
            new_dp |= (dp << s);
        }
        dp = new_dp;
    }

    if (dp[k]) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
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