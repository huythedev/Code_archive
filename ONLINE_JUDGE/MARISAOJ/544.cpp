// Author: huythedev
// Problem Link: https://marisaoj.com/problem/544
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

void genString(int len, string str) {
    bool sameChar = false;
    for (int i = 0; i < (int)str.sz - 1; ++i) {
        if (str[i] == str[i + 1]) sameChar = true;
    }

    if (str.sz == len) {
        if (sameChar)
            return;

        cout << str << ln;
        return;
    }

    genString(len, str + 'A');
    genString(len, str + 'B');
    genString(len, str + 'C');
}

void solve() {
    int n; cin >> n;

    genString(n, "");
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