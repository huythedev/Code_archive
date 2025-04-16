// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/405
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
    double average = 0;
    for(int i = 0; i < n; ++i) {
        int t; cin >> t;
        average += t;
    }
    average /= n;
    cout << fixed << setprecision(3) << average;

    time();
    return 0;
}