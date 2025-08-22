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

vector<bool> primes(2e5 + 5, true);
void sieve() {
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= (int)2e5; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= (int)2e5; j += i) primes[j] = false;
        }
    }
}

void solve() {
    int a, b; cin >> a >> b;

    for (; a <= b; ++a)
        if (primes[a]) cout << a << ln;
}

signed main() {
    docfile();
    fastio();
    sieve();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}