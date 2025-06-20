// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

    if (n == 1) {
        ll x, y; cin >> x >> y;
        cout << 1 << ln;
        return;
    }

    vector<ll> row(n), col(n);
    for (int i = 0; i < n; i++) {
        cin >> row[i] >> col[i]; 
    }

    ll minrow = *min_element(row.begin(), row.end()), maxrow = *max_element(row.begin(), row.end()), mincol = *min_element(col.begin(), col.end()), maxcol = *max_element(col.begin(), col.end());
    
    int cntrow = 0, cntrow2 = 0, cntcol = 0, cntcol2 = 0;
    for (int i = 0; i < n; i++) {
        if (row[i] == minrow) 
            cntrow++;
        if (row[i] == maxrow) 
            cntrow2++;
        if (col[i] == mincol) 
            cntcol++;
        if (col[i] == maxcol) 
            cntcol2++;
    }
    
    ll minrow2 = 1e18, maxrow2 = -1e18, mincol2 = 1e18, maxcol2 = -1e18;
    for (int i = 0; i < n; i++) {
        if (row[i] > minrow) 
            minrow2 = min(minrow2, row[i]);
        if (row[i] < maxrow) 
            maxrow2 = max(maxrow2, row[i]);
        if (col[i] > mincol) 
            mincol2 = min(mincol2, col[i]);
        if (col[i] < maxcol) 
            maxcol2 = max(maxcol2, col[i]);
    }
    
    ll res = 1LL << 62;
    for (int i = 0; i < n; i++) {
        ll min_r, max_r, min_c, max_c;
        if (row[i] > minrow || cntrow > 1) 
            min_r = minrow;
        else 
            min_r = minrow2;
        if (row[i] < maxrow || cntrow2 > 1) 
            max_r = maxrow;
        else 
            max_r = maxrow2;
        if (col[i] > mincol || cntcol > 1) 
            min_c = mincol;
        else 
            min_c = mincol2;
        if (col[i] < maxcol || cntcol2 > 1) 
            max_c = maxcol;
        else 
            max_c = maxcol2;
        
        ll w = max_c - min_c + 1, h = max_r - min_r + 1;
        ll area = w * h;
        ll cost;

        if (area > n - 1)
            cost = area;
        else 
            cost = min((w + 1) * h, w * (h + 1));

        res = min(res, cost);
    }

    cout << res << ln;
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