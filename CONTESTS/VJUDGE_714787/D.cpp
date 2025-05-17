// Author: huythedev
// Problem Link: https://vjudge.net/contest/714787#problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

const int MAXN = 1e5 + 5;
vector<bool> isPrime(MAXN + 1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= MAXN; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                isPrime[i] = false;
        }
    }
    for (int p = 2; p <= MAXN; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
}

signed main() {
    fastio();
    docfile();
    sieve();

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        auto it = upper_bound(primes.begin(), primes.end(), (ll)sqrt(n));
        ll choices = it - primes.begin();

        auto it2 = upper_bound(primes.begin(), primes.end(), min((ll)sqrt(k), (ll)sqrt(n)));
        
        ll gifts = choices - (it2 - primes.begin());

        cout << choices << " " << gifts << ln;
    }

    time();
    return 0;
}