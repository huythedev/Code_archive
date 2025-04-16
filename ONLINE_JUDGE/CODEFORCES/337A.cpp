// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/337/A
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

    int n, m;
    cin >> n >> m;
    vector<int> puzzles(m);
    for (int i = 0; i < m; ++i) {
        cin >> puzzles[i];
    }
    sort(puzzles.begin(), puzzles.end());
    int min_diff = INT_MAX;
    for (int i = 0; i <= m - n; ++i) {
        min_diff = min(min_diff, puzzles[i + n - 1] - puzzles[i]);
    }
    cout << min_diff << ln;

    time();
    return 0;
}