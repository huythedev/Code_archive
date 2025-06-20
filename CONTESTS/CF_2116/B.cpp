// Author: huythedev
// Problem Link: https://codeforces.com/contest/2116/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

const ll MOD = 998244353;

ll binpow(ll base, int exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int& x : p) cin >> x;
    vector<int> q(n);
    for(int& x : q) cin >> x;

    vector<int> vec(n), vec2(n);

    if (n > 0) {
        vec[0] = 0;
        vec2[0] = 0;
    }

    for (int i = 1; i < n; i++) {
        vec[i] = i;
        if (p[i] < p[vec[i - 1]]) {
            vec[i] = vec[i - 1];
        }

        vec2[i] = i;
        if (q[i] < q[vec2[i - 1]]) {
            vec2[i] = vec2[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        ll sum1 = (binpow(2, p[vec[i]]) + binpow(2, q[i - vec[i]])) % MOD;
        ll sum2 = (binpow(2, q[vec2[i]]) + binpow(2, p[i - vec2[i]])) % MOD;
        
        if (p[vec[i]] == q[vec2[i]]) {
            if (q[i - vec[i]] > p[i - vec2[i]]) {
                cout << sum1 << " ";
            } else {
                cout << sum2 << " ";
            }
        } else if (p[vec[i]] > q[vec2[i]]) {
            cout << sum1 << " ";
        } else {
            cout << sum2 << " ";
        }
    }
    
    cout << ln;
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