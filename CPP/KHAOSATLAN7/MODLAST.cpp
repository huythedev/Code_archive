#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

ll T, mod;

ll multiply(ll x, ll y) {
    x %= mod;
    y %= mod;
    ll q = ld(x) * y / mod;
    ll r = ll(x * y - mod * q) % ll(mod);
    if (r < 0) r += mod;
    return r;
}

ll divi(ll x, ll n) {
    if (n == 1) return 1;
    if (n & 1)
        return (1 + multiply(x, divi(x, n - 1))) % mod;
    return multiply(x + 1, divi(multiply(x, x), n / 2));
}

void solve(ll x, ll n) {
    ll p = 1;
    for (ll t = x; t > 0; t /= 10)
        p = (ll(p) * 10ll) % mod;
    cout << multiply(x, divi(p, n)) << '\n';
}

int main() {

    ll x, n;
    cin >> x >> n >> mod;
    solve(x, n);

    return 0;
}
