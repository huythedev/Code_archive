// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/10
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

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(2) << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    time();
    return 0;
}