// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/116/A
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
    int current_passengers = 0, max_capacity = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        current_passengers -= a;
        current_passengers += b;
        max_capacity = max(max_capacity, current_passengers);
    }

    cout << max_capacity << ln;

    time();
    return 0;
}