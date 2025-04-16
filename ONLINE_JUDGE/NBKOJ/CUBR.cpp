// Author: huythedev (https://huythedev.com)
// Problem Link: https://nbk.homes/problem/cubr
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "CUBR"
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

static vector<ll> primes;
bool isPrime(ll x) {
    if (x < 2) return false;
    for (ll p : primes) {
        if ((ll)p * p > x) break;
        if (x % p == 0) return (x == p);
    }
    return true;
}

void sieve() {
    const ll LIM = 90000;
    vector<bool> is_prime_small(LIM + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;
    for (ll i = 2; i * i <= LIM; i++)
        if (is_prime_small[i])
            for (ll j = i * i; j <= LIM; j += i)
                is_prime_small[j] = false;
    for (ll i = 2; i <= LIM; i++)
        if (is_prime_small[i]) primes.push_back(i);
}

int main() {
    fastio();
    docfile();
    sieve();

    int a; cin >> a;
    int res = 0;
    for (int i = 0; i < a; ++i) {
        ll tmp = (ll)pow(a, 3) - (ll)pow(i, 3);
        if (isPrime(tmp)) ++res;
    }
    cout << res;
    time();
    return 0;
}
