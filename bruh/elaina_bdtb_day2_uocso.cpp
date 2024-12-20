// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/elaina_bdtb_day2_uocso
#include <bits/stdc++.h>
using namespace std;

#define NAME "UOCSO"
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



    time();
    return 0;
}