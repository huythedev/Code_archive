// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "perfect"
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

ll sum_div(ll n) {
    ll res = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res += i;
            if (n / i != i)
                res += n / i;
        }
    }
    return res;
}

signed main() {
    fastio();
    docfile();

    for (ll i = 0; i <= (ll)1e15; ++i) {
        if (sum_div(i) == 2 * i) cout << i << ' ';
    }

    time();
    return 0;
}