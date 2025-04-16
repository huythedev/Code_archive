// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/4/A
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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
    
    int w;
    cin >> w;
    
    if (w > 2 && w % 2 == 0) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }

    time();
    return 0;
}