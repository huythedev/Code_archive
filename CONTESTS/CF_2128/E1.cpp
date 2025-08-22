// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

bool check(int x, int k, int n, const vector<int>& a, int& l, int& r) {
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + (a[i] >= x ? 1 : -1);
    }

    int minVal = 0, minIdx = 0;
    
    for (int r2 = k; r2 <= n; ++r2) {
        if (p[r2 - k] < minVal) {
            minVal = p[r2 - k];
            minIdx = r2 - k;
        }
        
        if (p[r2] >= minVal) {
            l = minIdx + 1;
            r = r2;
            return true;
        }
    }
    
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int vmax = 0;
    int l = -1, r = -1;

    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int curr_l, curr_r;
        
        if (check(mid, k, n, a, curr_l, curr_r)) {
            vmax = mid;
            l = curr_l;
            r = curr_r;
            lo = mid + 1;
        } 
        else {
            hi = mid - 1;
        }
    }

    cout << vmax << " " << l << " " << r << ln;
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