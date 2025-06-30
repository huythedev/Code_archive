// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin10_struct_time"
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

struct Time {
    ll h, m, s;
};

Time add(Time a, Time b) {
    Time res;
    res.s = a.s + b.s;
    res.m = a.m + b.m + res.s / 60;
    res.s %= 60;
    res.h = a.h + b.h + res.m / 60;
    res.m %= 60;
    return res;
}

Time diff(Time a, Time b) {
    ll t1 = a.h * 3600 + a.m * 60 + a.s;
    ll t2 = b.h * 3600 + b.m * 60 + b.s;
    ll d = abs(t1 - t2);
    Time res;
    res.h = d / 3600;
    d %= 3600;
    res.m = d / 60;
    res.s = d % 60;
    return res;
}

void solve() {
    Time a, b;
    cin >> a.h >> a.m >> a.s;
    cin >> b.h >> b.m >> b.s;
    
    Time tong = add(a, b);
    Time chenh = diff(a, b);
    
    cout << tong.h << ' ' << tong.m << ' ' << tong.s << ln;
    cout << chenh.h << ' ' << chenh.m << ' ' << chenh.s << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}