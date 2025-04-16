// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/723/A
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
    
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> positions = {x1, x2, x3};
    sort(positions.begin(), positions.end());
    int min_distance = positions[2] - positions[0];
    cout << min_distance << ln;

    time();
    return 0;
}