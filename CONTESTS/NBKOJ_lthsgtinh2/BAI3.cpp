// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI3"
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
    string bulbs; cin >> bulbs;
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < k; i++) {
        int c; cin >> c;

        for (int j = 0; j < c; j++) {
            int x; cin >> x;
            vec[x].push_back(i);
        }
    }

    vector<int> target(n + 1);
    for (int i = 1; i <= n; i++) {
        target[i] = (bulbs[i - 1] == '0' ? 1 : 0);
    }

    vector<int> res(n + 1, INT_MAX);
    for (int mask = 0; mask < (1 << k); mask++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            int xor_flip = 0;
            for (int op : vec[j]) {
                xor_flip ^= ((mask >> op) & 1);
            }

            if (xor_flip == target[j]) {
                tmp = j;
            }
            else {
                break;
            }
        }

        for (int i = 1; i <= tmp; i++) {
            res[i] = min(res[i], __builtin_popcount(mask));
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ln;
    }
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