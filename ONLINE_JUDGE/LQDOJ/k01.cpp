// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/k01
#include <bits/stdc++.h>
using namespace std;

#define NAME "k01"
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

int main() {
    fastio();
    docfile();

    int tests; cin >> tests;
    while(tests--) {
        int xa, ya, xm, ym; cin >> xa >> ya >> xm >> ym;
        // Find the (x, y) of the B for M to be the midpoint of AB
        // AB = sqrt((xa - xb)^2 + (ya - yb)^2)
        cout << 2 * xm - xa << " " << 2 * ym - ya << ln;
    }

    time();
    return 0;
}