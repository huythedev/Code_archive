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

vector<ll> pow10(19, 1);

void precompute() {
    for (int i = 1; i <= 18; ++i)
        pow10[i] = pow10[i - 1] * 10LL;
}

void solve() {
    ll n; 
    cin >> n;

    vector<ll> res;
    for (int k = 1; k <= 18; ++k) {
        if (pow10[k] + 1 > n) 
            continue;

        if (n % (pow10[k] + 1) == 0)
            res.push_back(n / (pow10[k] + 1));
    }

    sort(res.begin(), res.end());

    if (res.empty()) {
        cout << 0 << ln;
    }
    else {
        cout << (int)res.size() << ln;
        
        for (ll x : res) cout << x << ' ';
        cout << ln;
    }
}

signed main() {
    fastIO();
    fileIO();

    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}