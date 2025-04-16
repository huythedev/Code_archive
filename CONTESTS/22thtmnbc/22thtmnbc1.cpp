// Author: huythedev (https://huythedev.com)
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
    
    if (a1 == b1) {
        ll x = a1;
        if (x == 0) {
            if (a3 <= 0 && 0 <= b3) {
                count += (b2 - a2 + 1);
            }
        } else {
            ll leftY = max(a2, (a3 + x - 1) / x);  
            ll rightY = min(b2, b3 / x);
            
            if (leftY <= rightY) {
                count += (rightY - leftY + 1);
            }
        }
    }
    else if (a2 == b2) {
        ll y = a2;
        if (y == 0) {
            if (a3 <= 0 && 0 <= b3) {
                count += (b1 - a1 + 1);
            }
        } else {
            ll leftX = max(a1, (a3 + y - 1) / y);
            ll rightX = min(b1, b3 / y);
            
            if (leftX <= rightX) {
                count += (rightX - leftX + 1);
            }
        }
    }
    else if ((b1 - a1 > 10000) && (b2 - a2 > 10000)) {
        for (ll z = a3; z <= b3; ++z) {
            if (z == 0) {
                if (a1 <= 0 && 0 <= b1 && a2 <= 0 && 0 <= b2) {
                    count++;
                }
                continue;
            }
            
            for (ll x = 1; x * x <= z; ++x) {
                if (z % x == 0) {
                    ll y = z / x;
                    
                    if (a1 <= x && x <= b1 && a2 <= y && y <= b2) {
                        count++;
                    }
                    
                    if (x != y && a1 <= y && y <= b1 && a2 <= x && x <= b2) {
                        count++;
                    }
                }
            }
        }
    }
    else if (b1 - a1 <= b2 - a2) {
        for (ll x = a1; x <= b1; ++x) {
            if (x == 0) {
                if (a3 <= 0 && 0 <= b3) {
                    count += (b2 - a2 + 1);
                }
                continue;
            }
            
            ll leftBound = max(a2, (a3 + x - 1) / x); 
            ll rightBound = min(b2, b3 / x);
            
            if (leftBound <= rightBound) {
                count += (rightBound - leftBound + 1);
            }
        }
    } 
    else {
        for (ll y = a2; y <= b2; ++y) {
            if (y == 0) {
                if (a3 <= 0 && 0 <= b3) {
                    count += (b1 - a1 + 1);
                }
                continue;
            }
            
            ll leftBound = max(a1, (a3 + y - 1) / y); 
            ll rightBound = min(b1, b3 / y);
            
            if (leftBound <= rightBound) {
                count += (rightBound - leftBound + 1);
            }
        }
    }
    
    cout << count << ln;

    time();
    return 0;
}