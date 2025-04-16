// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1676/A
// davul
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

signed main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sum1 = s[0] - '0' + s[1] - '0' + s[2] - '0';
        int sum2 = s[3] - '0' + s[4] - '0' + s[5] - '0';
        if (sum1 == sum2) {
            cout << "YES" << ln;
        } else {
            cout << "NO" << ln;
        }
    }

    time();
    return 0;
}