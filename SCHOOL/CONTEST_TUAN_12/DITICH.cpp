// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DITICH"
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

signed main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    
    vector<ll> left_max(n + 1);
    left_max[0] = 2 * prefix_sum[0];
    for (int j = 1; j <= n; ++j) {
        left_max[j] = max(left_max[j - 1], 2 * prefix_sum[j]);
    }
    
    vector<ll> right_max(n + 1);
    right_max[n] = 2 * prefix_sum[n];
    for (int j = n - 1; j >= 0; --j) {
        right_max[j] = max(right_max[j + 1], 2 * prefix_sum[j]);
    }
    
    ll max_temp = LLONG_MIN;
    for (int j = 0; j <= n; ++j) {
        ll temp = left_max[j] - 2 * prefix_sum[j] + right_max[j];
        max_temp = max(max_temp, temp);
    }
    
    cout << max_temp - prefix_sum[n] << ln;

    time();
    return 0;
}