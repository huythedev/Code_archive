// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1475/A
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

bool isPowerOfTwo(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (isPowerOfTwo(n)) {
            cout << "NO" << ln;
        } else {
            cout << "YES" << ln;
        }
    }

    time();
    return 0;
}