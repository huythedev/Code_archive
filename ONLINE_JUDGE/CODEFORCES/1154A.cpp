// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1154/A

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

    vector<int> a(4);
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = a[3] - a[0];
    int y = a[3] - a[1];
    int z = a[3] - a[2];
    cout << x << " " << y << " " << z << ln;

    time();
    return 0;
}