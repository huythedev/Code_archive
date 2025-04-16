// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/397
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

    int a, b; cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "INFINITE SOLUTIONS";
        else cout << "NO SOLUTION";
    } else {
        if (b % a == 0) cout << -b / a;
        else cout << "NO SOLUTION";
    }

    time();
    return 0;
}