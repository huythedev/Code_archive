// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/540
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

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    int max_val = INT_MIN, min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        max_val = max(max_val, x);
        min_val = min(min_val, x);
    }

    cout << abs(max_val - min_val) << ln;

    time();
    return 0;
}