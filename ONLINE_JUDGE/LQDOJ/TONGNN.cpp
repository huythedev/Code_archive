// Author: Perry (https://perrythedev.com)^
#include <bits/stdc++.h>
using namespace std;

#define NAME "TONGNN"
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

    ll m, n;
    cin >> m >> n;
    
    if (n % m != 0) {
        cout << -1 << endl;
        return 0;
    }
    
    ll mn = n / m;
    ll result = -1;
    
    for (ll d = 1; d * d <= mn; ++d) {
        if (mn % d == 0) {
            ll d1 = d;
            ll d2 = mn / d;
            
            if (gcd(d1, d2) == 1) {
                ll A = m * d1;
                ll B = m * d2;
                if (result == -1 || A + B < result) {
                    result = A + B;
                }
            }
        }
    }
    
    cout << result << endl;
    
    time();
    return 0;
}