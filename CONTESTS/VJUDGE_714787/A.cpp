// Author: huythedev
// Problem Link: https://vjudge.net/contest/714787#problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

ll pow_mod(ll a, ll b, ll n) {
    ll res = 1;
    a %= n;
    while (b > 0) {
        if (b & 1) res = mulmod(res, a, n);
        a = mulmod(a, a, n);
        b >>= 1;
    }
    return res;
}

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    ll s = 0, d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    vector<ll> witnesses = {2, 3, 5, 7, 11, 13, 17};
    for (ll a : witnesses) {
        if (a >= n) break;
        ll x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool passed = false;
        for (ll r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                passed = true;
                break;
            }
        }
        if (!passed) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    ll x = rand() % (n - 2) + 2, y = x, c = rand() % (n - 1) + 1, d = 1;
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = gcd(x > y ? x - y : y - x, n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}

void factorize(ll n, map<ll, int>& factors) {
    if (n <= 1) return;
    if (is_prime(n)) {
        factors[n]++;
        return;
    }
    ll f = pollard_rho(n);
    int cnt = 0;
    while (n % f == 0) {
        n /= f;
        cnt++;
    }
    map<ll, int> f_factors;
    factorize(f, f_factors);
    for (auto [p, e] : f_factors) {
        factors[p] += e * cnt;
    }
    factorize(n, factors);
}

ll sum_divs_small(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res += i;
            if (i != n / i) {
                res += n / i;
            }
        }
    }
    return res - n;
}

ll sum_divs_large(ll n) {
    if (n == 1) return 0;
    if (is_prime(n)) return 1;
    map<ll, int> factors;
    factorize(n, factors);
    ll sum = 1;
    for (auto [p, a] : factors) {
        ll term = 0, pow_p = 1;
        for (int i = 0; i <= a; i++) {
            term += pow_p;
            pow_p *= p;
        }
        sum *= term;
    }
    return sum - n;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    
    while (t--) {
        ll n; cin >> n;
        // if (n <= (ll)1e10) {
        //     cout << sum_divs_small(n) << ln;
        // } else {
            cout << sum_divs_large(n) << ln;
        // }
    }

    return 0;
}