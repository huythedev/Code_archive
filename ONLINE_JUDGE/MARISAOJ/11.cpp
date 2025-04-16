// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/11
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

bool isSquare(ll n) {
    ll x = sqrt(n);
    return x * x == n;
}

int main() {
    fastio();
    docfile();

    ll n; cin >> n;
    cout << (isSquare(n) ? "YES" : "NO");

    time();
    return 0;
}