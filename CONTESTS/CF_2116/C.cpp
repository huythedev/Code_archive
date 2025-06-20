// Author: huythedev
// Problem Link: https://codeforces.com/contest/2116/problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    vector<int> m(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        m[i] = a[i] / g;
        if (m[i] == 1) k++;
    }

    if (k > 0) {
        cout << n - k << ln;
        return;
    }

    int ans = n + n;
    for (int i = 0; i < n; i++) {
        vector<int> primes;
        int x = m[i];
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                primes.push_back(d);
                while (x % d == 0) x /= d;
            }
        }
        if (x > 1) primes.push_back(x);
        int tmp = primes.sz;
        if (tmp == 0) {
            ans = min(ans, n - 1);
            continue;
        }
        vector<int> mask(n);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            mask[j] = 0;
            for (int t = 0; t < tmp; t++) {
                if (m[j] % primes[t]) {
                    mask[j] |= (1 << t);
                }
            }
        }
        vector<int> dp(1 << tmp, n + 1);
        dp[0] = 0;
        for (int state = 0; state < (1 << tmp); state++) {
            if (dp[state] == n + 1) continue;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                dp[state | mask[j]] = min(dp[state | mask[j]], dp[state] + 1);
            }
        }
        int ki = dp[(1 << tmp) - 1];
        ans = min(ans, ki + n - 1);
    }
    
    cout << ans << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}