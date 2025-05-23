// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/758/A

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
    vector<int> welfare(n);
    int max_welfare = 0;

    for (int i = 0; i < n; ++i) {
        cin >> welfare[i];
        if (welfare[i] > max_welfare) {
            max_welfare = welfare[i];
        }
    }

    int total_burles = 0;
    for (int i = 0; i < n; ++i) {
        total_burles += (max_welfare - welfare[i]);
    }

    cout << total_burles << ln;

    time();
    return 0;
}