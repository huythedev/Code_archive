// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6heroteam
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6heroteam"
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

const ll mod = 998244353;

ll modpow(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<ll> P(n), Q(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i] >> Q[i];
    }

    ll total = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (P[i] < P[j] + P[k] && P[j] < P[i] + P[k] && P[k] < P[i] + P[j]) {
                    ll x = Q[i], y = Q[j], z = Q[k];
                    ll expr = (ll)x * y - (ll)x * z + (ll)z * z - (ll)y * z;
                    ll D = 1 + (x != y) + (expr != 0);
                    ll sum = (P[i] + P[j] + P[k]) % mod;
                    ll strength = modpow(sum, D, mod);
                    total = (total + strength) % mod;
                }
            }
        }
    }
    cout << total << endl;

    time();
    return 0;
}