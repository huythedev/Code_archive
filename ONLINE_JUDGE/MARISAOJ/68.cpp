// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/68
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

bool comp(vector <int> &a, vector <int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<vector<int>> table(n, vector<int>(3));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < 3; ++j) cin >> table[i][j];

    sort(table.begin(), table.end(), comp);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << table[i][j] << ' ';
        cout << ln;
    }

    time();
    return 0;
}