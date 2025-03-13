// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/581/A
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

    int a, b;
    cin >> a >> b;
    int complete_outfits = min(a, b);
    int remaining_socks = abs(a - b) / 2;
    cout << complete_outfits << " " << remaining_socks << ln;

    time();
    return 0;
}