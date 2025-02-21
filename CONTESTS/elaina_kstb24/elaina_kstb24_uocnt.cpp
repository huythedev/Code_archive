// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/elaina_kstb24_uocnt
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "UOCNT"
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

const int MAXN = 1e6;
vector<int> primes;
bitset<MAXN + 1> is_prime_sieve;

void sieve() {
    is_prime_sieve.set();
    is_prime_sieve[0] = is_prime_sieve[1] = 0;
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime_sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXN; j += i) {
                is_prime_sieve[j] = 0;
            }
        }
    }
}

int count_prime_divs(ll n) {
    ll res = 0;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            ++res;
            while (n % p == 0) {
                n /= p;
            }
        }
    }
    if (n > 1) {
        ++res;
    }
    return res;
}

int main() {
    fastio();
    docfile();
    sieve();

    ll n; cin >> n;

    cout << count_prime_divs(n) << ln;

    time();
    return 0;
}
