// Author: huythedev
// Problem Link: 
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

bool isPrime(ll num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    
    for (ll i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    string s = to_string(n);
    
    for (int i = 1; i <= (int)s.sz; ++i) {
        string prefix = s.substr(0, i);
        ll num = stoll(prefix);
        
        if (!isPrime(num)) {
            cout << "KHONG" << ln;
            return;
        }
    }
    
    cout << "PHAI" << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}