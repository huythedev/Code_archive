// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/996/A
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

    int n;
    cin >> n;
    int bills[] = {100, 20, 10, 5, 1};
    int count = 0;

    for (int i = 0; i < 5; ++i) {
        count += n / bills[i];
        n %= bills[i];
    }

    cout << count << ln;

    time();
    return 0;
}