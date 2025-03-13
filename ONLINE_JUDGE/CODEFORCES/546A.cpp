// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/546/A
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

    int k, n, w;
    cin >> k >> n >> w;

    int total_cost = 0;
    for (int i = 1; i <= w; ++i) {
        total_cost += i * k;
    }

    int borrow = max(0, total_cost - n);
    cout << borrow << ln;

    time();
    return 0;
}