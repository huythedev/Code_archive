// Author: huythedev
// Problem Link: https://codeforces.com/contest/2111/problem/B
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

vector<ll> fib(12);

void precompute() {
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 11; i++) 
        fib[i] = fib[i - 1] + fib[i - 2];
}

bool canFit(int n, ll w, ll l, ll h) {
    vector<ll> vec = {w, l, h};
    sort(vec.begin(), vec.end());
    ll minval = vec[0], mid_dim = vec[1], max_dim = vec[2];

    if (fib[n] > minval || fib[n] > mid_dim) return false;

    ll min_height = fib[n]; 
    ll sum_width = 0;
    for (int i = 1; i <= n; i++) sum_width += fib[i];
    if (sum_width <= minval && fib[n] <= mid_dim) {
        return max_dim >= min_height;
    }
    
    return max_dim >= fib[n + 1];
}

void solve() {
    int n, m;
    cin >> n >> m;
    string res = "";
    for (int i = 0; i < m; i++) {
        ll w, l, h;
        cin >> w >> l >> h;
        res += canFit(n, w, l, h) ? "1" : "0";
    }
    cout << res << "\n";
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