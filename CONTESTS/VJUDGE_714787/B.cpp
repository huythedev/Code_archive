// Author: huythedev
// Problem Link: https://vjudge.net/contest/714787#problem/B
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

const int LIM = 1e6;
vector<bool> isPrime;

void sieve() {
    isPrime.assign(LIM + 1, true);
    if (LIM >= 0) isPrime[0] = false;
    if (LIM >= 1) isPrime[1] = false;
    for (int p = 2; p * p <= LIM; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= LIM; i += p)
                isPrime[i] = false;
        }
    }
}

signed main() {
    fastio();
    docfile();
    sieve();

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;

        ll root_val = round(sqrt((ld)x));

        if (root_val > 0 && root_val * root_val == x) {
            if (root_val <= LIM && isPrime[root_val]) {
                cout << "YES" << ln;
            } else {
                cout << "NO" << ln;
            }
        } else {
            cout << "NO" << ln;
        }
    }

    time();
    return 0;
}