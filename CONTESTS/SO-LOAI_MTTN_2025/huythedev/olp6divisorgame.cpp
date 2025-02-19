// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6divisorgame
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6divisorgame"
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

ll solve(ll n) {
    if (n < 4) 
        return 0;
    
    ll arius = 0, boreas = 0;
    bool arius_turn = true;
    stack<ll> s;
    s.push(n);
    
    while (!s.empty()) {
        ll current = s.top();
        s.pop();
        
        if (current < 4) continue;
        
        ll tmp2 = 0, tmp3 = 0;
        for (ll i = 2; i * i <= current; ++i) {
            if (current % i == 0) {
                ll p = current / i;
                if (i < p && p < current) {
                    tmp2 = i;
                    tmp3 = p;
                    break;
                }
            }
        }
        
        if (tmp2 == 0) 
            continue;
        
        if (arius_turn) {
            arius += tmp2 + tmp3;
        } 
        else {
            boreas += tmp2 + tmp3;
        }
        
        arius_turn = !arius_turn;
        s.push(tmp2);
        s.push(tmp3);
    }
    
    return arius - boreas;
}

int main() {
    fastio();
    docfile();
    
    ll n;
    cin >> n;
    cout << solve(n) << ln;
    
    time();
    return 0;
}
