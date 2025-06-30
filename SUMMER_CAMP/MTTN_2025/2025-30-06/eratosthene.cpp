// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "eratosthene"
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

const int LIM = 5e6 + 5;

vector<bool> isPrime(LIM, true);
vector<ll> primes;

void sieve() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= LIM; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = (ll)i * i; j <= LIM; j += i) 
                isPrime[j] = false;
        }
    }
}

void solve() {
    ll l, r; cin >> l >> r;

    vector<bool> vec(r - l + 1, true);
    if (l == 1) 
        vec[0] = false;

    for (ll i : primes) {
        if (i * i > r) 
            break;
        
        ll start = max(i * i, (l + i - 1) / i * i);

        for (ll j = start; j <= r; j += i) 
            vec[j - l] = false;
    }

    ll cnt = 0;
    for (ll i = 0; i <= r - l; ++i)
        if (vec[i]) 
            ++cnt;

    cout << cnt << ln;
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