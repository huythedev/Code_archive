// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "LAMPS"
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

    int tests; cin >> tests;
    while (tests--) {
        ll rows, cols; cin >> rows >> cols;
        
        ll sqrt_rows = sqrtl(rows);
        ll sqrt_cols = sqrtl(cols);
        
        cout << sqrt_rows * cols + rows * sqrt_cols - 2 * sqrt_rows * sqrt_cols << ln;
    }

    time();
    return 0;
}