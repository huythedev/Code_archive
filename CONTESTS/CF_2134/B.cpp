// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

ll modInverse(ll a, ll m) {
    ll m2 = m;
    ll x = 1, y = 0;

    if (m == 1) 
        return 0;

    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0) 
        x += m2;

    return x;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll g = a[0];
    for(int i = 1; i < n; i++) 
        g = gcd(g, a[i]);

    if (g > 1) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }

        cout << ln;
        return;
    }

    ll d = 2;
    while (d <= k + 1) {
        if (gcd(d, k) == 1)
            break;
        d++;
    }

    ll k2 = modInverse(k % d, d);
    for (int i = 0; i < n; i++) {
        ll tmp = (d - a[i] % d) % d;
        a[i] += ((tmp * k2) % d) * k;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    cout << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}