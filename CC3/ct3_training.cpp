// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ct3_training"
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
    int n, c, k; cin >> n >> c >> k;
    int ans = 0;
    vector<ll> costs;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;

        if (a >= k) {
            ans++;
        }
        else if (b > 0) {
            ll tmp = (k - a + b - 1) / b;
            costs.push_back(tmp);
        }
    }

    sort(costs.begin(), costs.end());

    for (ll i : costs) {
        if (c >= i) {
            c -= i;
            ans++;
        } 
        else break;
    }

    cout << ans << ln;
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