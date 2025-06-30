// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/D
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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
vector<ll> vec(MAXN + 1);

void precompute() {
    vec[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        vec[i] = (MOD - (MOD / i) * vec[MOD % i] % MOD) % MOD;
    }
}

ll calc(ll n, int k) {
    if (k == 0) 
        return 1;

    ll ans = 1;
    for (int i = 0; i < k; ++i) {
        ll num = (n - i) % MOD;
        if (num < 0) 
            num += MOD;

        ans = (ans * num) % MOD;
        ans = (ans * vec[i + 1]) % MOD;
    }

    return ans;
}

void solve() {
    int a, b, k; cin >> a >> b >> k;

    ll rows = ((ll)(a - 1) * k + 1);
    ll cols = ((((ll)(b - 1) * k) % MOD) * calc(rows, a) % MOD + 1) % MOD;

    cout << rows % MOD << " " << cols << ln;
}

signed main() {
    docfile();
    fastio();
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}