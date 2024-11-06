#include <bits/stdc++.h>
using namespace std;

#define NAME "maxpower"
#define ln endl

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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

map<ll, ll> ptts(ll m) {
    map<ll, ll> tsnt;
    for (ll i = 2; i * i <= m; i++) {
        while (m % i == 0) {
            tsnt[i]++;
            m /= i;
        }
    }
    if (m > 1) 
        tsnt[m]++;

    return tsnt;
}

ll count(ll n, ll p) {
    ll res = 0;
    ll power = p;
    while (power <= n) {
        res += n / power;
        if (n / power < p) break;
        power *= p;
    }
    return res;
}

int main() {
    fastio();
    docfile();

    ll n, m;
    cin >> n >> m;

    map<ll, ll> primeFactors = ptts(m);
    ll k = LLONG_MAX;

    for (auto &factor : primeFactors) {
        ll p = factor.first;
        ll exp = factor.second;
        ll tmp = count(n, p);
        k = min(k, tmp / exp);
    }

    if (k == LLONG_MAX || k == 0) 
        k = -1;

    cout << k << ln;

    time();
    return 0;
}
