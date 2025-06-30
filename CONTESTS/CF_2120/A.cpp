// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    ll A = (ll)l1 * b1 + l2 * b2 + l3 * b3;
    int S = 0;
    while ((ll)S * S < A) 
        S++;

    if ((ll)S * S != A) {
        cout << "NO" << ln;
        return;
    }

    bool possible = false;
    if (l1 == S && l2 == S && l3 == S && b1 + b2 + b3 == S) 
        possible = true;
    if (b1 == S && b2 == S && b3 == S && l1 + l2 + l3 == S) 
        possible = true;
    if (b1 == S && l2 == l3 && l2 == S - l1 && b2 + b3 == S)
        possible = true;
    if (b2 == S && l1 == l3 && l1 == S - l2 && b1 + b3 == S)
        possible = true;
    if (b3 == S && l1 == l2 && l1 == S - l3 && b1 + b2 == S)
        possible = true;
    if (l1 == S && b2 == b3 && b2 == S - b1 && l2 + l3 == S)
        possible = true;
    if (l2 == S && b1 == b3 && b1 == S - b2 && l1 + l3 == S)
        possible = true;
    if (l3 == S && b1 == b2 && b1 == S - b3 && l1 + l2 == S)
        possible = true;

    if (possible) 
        cout << "YES" << ln;
    else 
        cout << "NO" << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}