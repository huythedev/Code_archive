#include <bits/stdc++.h>
using namespace std;

#define NAME "exp"
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


const ll MOD = 1e9 + 7;
const ll MOD_PHI = MOD - 1; 

ll power(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    
    return result;
}

ll solve(ll a, ll b, ll c) {
    ll exp = power(b, c, MOD_PHI);
    return power(a, exp, MOD);
}

int main() {
    fastio();
    docfile();

    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a, b, c) << ln;
    }

    time();
    return 0;
}