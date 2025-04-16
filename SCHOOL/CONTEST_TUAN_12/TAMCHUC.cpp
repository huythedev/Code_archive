// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "TAMCHUC"
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

const int MOD = 1e9 + 7;

signed main() {
    fastio();
    docfile();

    int n, q; cin >> n >> q;
    vector<ll> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<ll> b(n + 1, 0);
    vector<ll> prefix_sum(n + 1, 0);

    b[1] = max(0LL, 1LL - x[1]);
    prefix_sum[1] = b[1] % MOD;

    for (int i = 2; i <= n; ++i) {
        b[i] = max(0LL, 2 * b[i - 1] - x[i]);
        prefix_sum[i] = (prefix_sum[i - 1] + b[i]) % MOD;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = (prefix_sum[r] - (l == 1 ? 0 : prefix_sum[l - 1]) + MOD) % MOD;
        cout << ans << "\n";
    }

    time();
    return 0;
}