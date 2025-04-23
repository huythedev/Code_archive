// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2074/problem/C

#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

    // Begin solution modifications
    int t; 
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int k = 31 - __builtin_clz(x); // highest set bit index
        int M = 1 << k;
        int r = x - M; // lower part bits
        // if x is a power of 2 or if lower k bits are all set then any y is a subset of x
        if(r == 0 || r == M - 1){
            cout << -1 << "\n";
            continue;
        }
        int candidate = -1;
        for (int i = 0; i < k; i++){
            if ((r & (1 << i)) == 0) { // found a missing bit
                candidate = r | (1 << i);
                break;
            }
        }
        if(candidate != -1 && candidate < x)
            cout << candidate << "\n";
        else
            cout << -1 << "\n";
    }
    // End solution modifications

    time();
    return 0;
}