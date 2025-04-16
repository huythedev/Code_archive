// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/492/B
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

    int n, l;
    cin >> n >> l;
    vector<int> lanterns(n);
    for (int i = 0; i < n; ++i) {
        cin >> lanterns[i];
    }
    sort(lanterns.begin(), lanterns.end());

    double max_distance = max(lanterns[0], l - lanterns[n-1]) * 2;
    for (int i = 1; i < n; ++i) {
        max_distance = max(max_distance, (double)(lanterns[i] - lanterns[i-1]));
    }

    cout << fixed << setprecision(10) << max_distance / 2.0 << ln;

    time();
    return 0;
}