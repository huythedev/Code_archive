// Author: Perry
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "GIFTS"
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

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    sort(a.begin(), a.end());
    
    int l = 0, r = n, res = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        ll total = 0;
        for (int i = 0; i < mid; i++) {
            total += a[i];
        }
        
        ll discount = 0;
        for (int i = mid - 1; i >= 0 && (mid - 1 - i) < k; i--) {
            discount += a[i] / 2;
        }
        
        if (total - discount <= m) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}