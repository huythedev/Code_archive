// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/20
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
    ll a = 0, b = 1, c;
    for(int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;

    time();
    return 0;
}