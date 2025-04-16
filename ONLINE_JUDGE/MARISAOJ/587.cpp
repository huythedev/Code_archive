// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/587
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

    int x, a, b, c, d; cin >> x >> a >> b >> c >> d;
    int cost = 0;
    if(x <= 50) cost = x * a;
    else if(x <= 100) cost = 50 * a + (x - 50) * b;
    else if(x <= 150) cost = 50 * a + 50 * b + (x - 100) * c;
    else cost = 50 * a + 50 * b + 50 * c + (x - 150) * d;

    cout << cost;

    time();
    return 0;
}