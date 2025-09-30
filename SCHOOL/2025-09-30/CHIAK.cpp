// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CHIAK"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
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
    long long n, k;
    if (!(cin >> n >> k)) { cout << 0; return; }
    if (k <= 0) { cout << 0; return; } // guard (spec says k>0)

    vector<long long> a(n);
    for (ll &x : a) cin >> x;

    unordered_map<long long, long long> freq;
    freq.reserve(static_cast<size_t>(min(n + 5, 1000000LL)));
    freq.max_load_factor(0.7f);

    long long ans = 0;
    long long pref = 0;

    freq[0] = 1; // empty prefix

    for (long long x : a) {
        pref += x;

        // Robust normalization for negatives:
        long long r = ((pref % k) + k) % k;

        auto it = freq.find(r);
        if (it != freq.end()) {
            ans += it->second;
            ++(it->second);
        } else {
            freq[r] = 1;
        }
    }

    cout << ans;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}