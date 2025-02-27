// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc1
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc1"
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
    
    ll a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    
    ll count = 0;
    
    for (ll x = a1; x <= b1; ++x) {
        ll leftBound = max(a2, (a3 + x - 1) / x); 
        ll rightBound = min(b2, b3 / x);
        
        if (leftBound <= rightBound) {
            count += (rightBound - leftBound + 1);
        }
    }
    
    cout << count << ln;

    time();
    return 0;
}