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

vector<ll> vec;
vector<int> vec2;

void precompute() {
    vector<ll> primes = {2, 3, 5, 7};
    for (int mask = 0; mask < 16; ++mask) {
        ll m = 1;
        int tmp = 1;
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                m *= primes[i];
                tmp *= -1;
            }
        }
        vec.push_back(m);
        vec2.push_back(tmp);
    }
}

ll calc(ll n) {
    ll sum = 0;
    for (int i = 0; i < 16; ++i) {
        sum += (ll)(vec2[i]) * (n / vec[i]);
    }
    return sum;
}

void solve() {
    ll l, r;
    cin >> l >> r;

    cout << calc(r) - calc(l - 1) << ln;
}

signed main() {
    docfile();
    fastio();
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}