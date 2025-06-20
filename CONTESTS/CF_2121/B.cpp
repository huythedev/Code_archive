// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    int n; string s; cin >> n >> s;

    if (n < 3) {
        cout << "No" << ln;
        return;
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] | (1 << (s[i] - 'a'));
    }
    vector<int> suffix(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] | (1 << (s[i + 1] - 'a'));
    }

    bool possible = false;
    for (int i = 1; i <= n - 2; ++i) {
        int bit = 1 << (s[i] - 'a');
        if ((prefix[i] & bit) || (suffix[i] & bit)) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << ln;
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