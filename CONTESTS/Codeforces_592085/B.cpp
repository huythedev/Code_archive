// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/gym/592085/problem/B

#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

ll digit_root(ll n) {
    if (n == 0) return 0;
    if (n % 9 == 0) return 9;
    return n % 9;
}

ll sum_digit_root(ll n) {
    ll cycles = n / 9;
    ll remainder = n % 9;
    
    ll sum = cycles * 45;
    
    for (ll i = 1; i <= remainder; i++) {
        sum += i;
    }
    
    return sum;
}

int main() {
    fastio();
    docfile();

    int T;
    cin >> T;
    
    while (T--) {
        ll L, R;
        cin >> L >> R;
        
        ll res = sum_digit_root(R) - sum_digit_root(L - 1);
        cout << res << "\n";
    }

    time();
    return 0;
}