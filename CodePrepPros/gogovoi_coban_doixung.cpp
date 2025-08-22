// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_coban_doixung"
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

bool isPalindrome(string s) {
    int n = (int)s.sz;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

void solve() {
    string s; cin >> s;

    int n = (int)s.sz;
    int res = n;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isPalindrome(s.substr(i, j - i + 1))) ++res;
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