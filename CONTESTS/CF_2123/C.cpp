// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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
        
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> prefix_min(n);
    prefix_min[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix_min[i] = min(prefix_min[i-1], a[i]);
    
    vector<int> suffix_max(n);
    suffix_max[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i+1], a[i]);
    
    string res;
    for (int i = 0; i < n; i++) {
        if (a[i] == prefix_min[i] || a[i] == suffix_max[i]) {
            res += '1';
        } 
        else {
            res += '0';
        }
    }
    
    cout << res << ln;
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