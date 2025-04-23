// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/A

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

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        ll e = k - 1; 
        if (n % 2 == 0) {
            cout << (n + e - 1) / e << endl;
        } else {
            cout << 1 + ((n - k) + e - 1) / e << endl;
        }
    }

    time();
    return 0;
}