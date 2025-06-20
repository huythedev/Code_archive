// Author: huythedev
// Problem Link: https://marisaoj.com/problem/323
#include <bits/stdc++.h>
using namespace std;

#define NAME "323"
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

set<string> result;

void print_result() {
    for (string str : result) {
        for (char c : str) {
            cout << c << ' ';
        }
        cout << ln;
    }
}

void solve() {
    int n, k; cin >> n >> k;

    int tmp = 1 << n;
    for (int i = 0; i < tmp; ++i) {
        string s = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) s += to_string(j + 1);
        }
        // cout << s << ln;
        if ((int)s.sz == k) result.insert(s);
    }

    print_result();
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