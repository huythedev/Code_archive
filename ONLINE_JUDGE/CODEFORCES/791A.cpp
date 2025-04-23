// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/791/A

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
    
    int a, b;
    cin >> a >> b;
    
    int years = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        years++;
    }
    
    cout << years << ln;

    time();
    return 0;
}