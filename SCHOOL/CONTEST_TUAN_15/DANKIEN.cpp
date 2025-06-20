// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DANKIEN"
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

    ll n; cin >> n;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<ll> prefix_a(n);
    vector<ll> prefix_ax(n);
    prefix_a[0] = a[0];
    prefix_ax[0] = a[0] * x[0];
    for (ll i = 1; i < n; i++) {
        prefix_a[i] = prefix_a[i - 1] + a[i];
        prefix_ax[i] = prefix_ax[i - 1] + a[i] * x[i];
    }
    
    ll S = prefix_a[n - 1];
    ll target = (S + 1) / 2;
    ll k = 0;
    while (k < n && prefix_a[k] < target) {
        k++;
    }
    
    ll left_sum = (k > 0) ? x[k] * prefix_a[k - 1] - prefix_ax[k - 1] : 0;
    ll right_sum = (k < n - 1) ? (prefix_ax[n - 1] - prefix_ax[k]) - x[k] * (prefix_a[n - 1] - prefix_a[k]) : 0;
    ll total_distance = left_sum + right_sum;
    
    cout << total_distance << ln;

    time();
    return 0;
}
