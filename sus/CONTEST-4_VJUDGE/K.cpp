// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/K
#include <bits/stdc++.h>
using namespace std;

#define NAME "K"
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

ld calc(ld loan, ld monthly, int months, ld monthly_rate) {
    ld res = loan;
    for (int i = 0; i < months; ++i) {
        res = res * (1.0L + monthly_rate);
        res -= monthly;
    }
    return res;
}

signed main() {
    fastio();
    docfile();

    ll w0, w;
    int m;
    cin >> w0 >> w >> m;

    ld loan = static_cast<ld>(w0), monthly = static_cast<ld>(w);

    ld lo = 0.0L, hi = 3.0L;   

    for (int i = 0; i < 100; ++i) {
        ld mid_rate = lo + (hi - lo) / 2.0L; 
        ld remain = calc(loan, monthly, m, mid_rate);

        if (remain > 1e-9L) {
            hi = mid_rate;
        } else {
            lo = mid_rate;
        }
    }

    cout << fixed << setprecision(1) << lo * 100.0L << ln;
    
    time();
    return 0;
}