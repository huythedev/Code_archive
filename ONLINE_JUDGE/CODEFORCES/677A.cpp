// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/677/A
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

    int n, h;
    cin >> n >> h;
    int width = 0;

    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai > h) {
            width += 2;
        } else {
            width += 1;
        }
    }

    cout << width << ln;
    return 0;
}