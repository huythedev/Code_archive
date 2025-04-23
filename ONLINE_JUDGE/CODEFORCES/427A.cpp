// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/427/A

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
    int untreated = 0, police = 0;
    for (int i = 0; i < n; ++i) {
        int event;
        cin >> event;
        if (event == -1) {
            if (police > 0) {
                police--;
            } else {
                untreated++;
            }
        } else {
            police += event;
        }
    }
    cout << untreated << ln;

    time();
    return 0;
}