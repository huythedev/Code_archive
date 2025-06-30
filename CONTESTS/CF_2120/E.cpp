// Author: huythedev
// Problem Link: https://codeforces.com/contest/2120/problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    ll l = 0, r = 1e12, x = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2, total = 0;
        
        for (ll i : a) {
            ll tmp = 0;
            if (mid > 0) {
                if (mid <= i) 
                    tmp = mid;
                else if (mid - k <= i) 
                    tmp = i;
                else 
                    tmp = mid - k;
            }

            total += tmp;
            if (total >= sum) 
                break;
        }

        if (total >= sum) {
            x = mid;
            r = mid - 1;
        } 
        else {
            l = mid + 1;
        }
    }

    ll s = 0, ans = 0;
    for (ll i : a) {
        ll tmp = 0;
        if (x - 1 > 0) {
            if (x - 1 <= i) 
                tmp = x - 1;
            else if (x - 1 - k <= i) 
                tmp = i;
            else 
                tmp = x - 1 - k;
        }

        s += tmp;
        if (tmp <= i) 
            ans += tmp * (tmp + 1) / 2;
        else 
            ans += tmp * (tmp + 1) / 2 + k * (tmp - i);
    }

    ans += (sum - s) * x;
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