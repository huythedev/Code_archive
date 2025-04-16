// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1409/A
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

int min_moves(int a, int b) {
    int diff = abs(a - b);
    return diff / 10 + (diff % 10 != 0);
}

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << min_moves(a, b) << ln;
    }

    time();
    return 0;
}