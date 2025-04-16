// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/hueict25v1trangtrai
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "hueict25v1trangtrai"
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

    int n, l, r, k; cin >> n >> l >> r >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }
    
    cout << sum / n << ln;

    time();
    return 0;
}