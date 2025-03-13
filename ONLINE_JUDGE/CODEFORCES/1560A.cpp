// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1560/A
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

void solve() {
    int k;
    cin >> k;
    int count = 0, num = 0;
    while (count < k) {
        num++;
        if (num % 3 != 0 && num % 10 != 3) {
            count++;
        }
    }
    cout << num << ln;
}

signed main() {
    fastio();
    docfile();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    time();
    return 0;
}