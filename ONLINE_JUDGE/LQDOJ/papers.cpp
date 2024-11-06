#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

ll MOD = 1e9 + 7;

ll inverse(ll a, ll m) {
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

ll xuly(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++) {
        res = (res * (n - i + 1)) % MOD;
        res = (res * 1LL * inverse(i, MOD)) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll m, n;
    cin >> m >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll S = m - accumulate(a.begin(), a.end(), 0LL);
    if (S < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << xuly(S + n - 1, n - 1) % MOD << endl;
    return 0;
}