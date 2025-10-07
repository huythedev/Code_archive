// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
    int A, B; cin >> A >> B;
    unordered_map<int, int> A_vals, B_vals;
    for (int i = 0; i < A; ++i) {
        int n; cin >> n;
        A_vals[n]++;
    }
    for (int i = 0; i < B; ++i) {
        int n; cin >> n;
        B_vals[n]++;
    }

    vector<int> res;
    if ((int)A_vals.size() > (int)B_vals.size()) {
        for (auto [val, freq] : B_vals) {
            if (A_vals[val]) res.push_back(val);
        }
    }
    else {
        for (auto [val, freq] : A_vals) {
            if (B_vals[val]) res.push_back(val);
        }
    }

    sort(res.begin(), res.end());

    for (int i : res) cout << i << ' ';
    cout << ln;
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