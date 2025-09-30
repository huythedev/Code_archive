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
    cin >> n >> k;

    unordered_map<long long, long long> freq;
    freq.reserve((size_t)min<long long>(n + 5, 2000000));
    freq[0] = 1;

    long long ans = 0;
    long long pref = 0;

    for (long long i = 0; i < n; ++i) {
        long long x; cin >> x;
        pref = (pref + x) % k;
        if (pref < 0) pref += k;
        auto it = freq.find(pref);
        if (it != freq.end()) {
            ans += it->second;
            ++(it->second);
        } else {
            freq[pref] = 1;
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
