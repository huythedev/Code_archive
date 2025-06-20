// Author: huythedev
// Problem Link: https://codeforces.com/contest/2110/problem/F
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

inline int f(int x, int y) {
    return (x % y) + (y % x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int b = 0;
    int m = 0;
    int m2 = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int max_f = 0;
        if (!s.empty()) {
            max_f = max(max_f, f(x, m));
            if (m2 > 0) {
                max_f = max(max_f, f(x, m2));
            }
            auto lb = s.lower_bound(x);
            if (lb != s.begin()) {
                --lb;
                max_f = max(max_f, f(x, *lb));
            }
            auto ub = s.upper_bound(x);
            if (ub != s.end()) {
                max_f = max(max_f, f(x, *ub));
            }
        }

        b = max(b, max_f);

        if (x > m) {
            m2 = m;
            m = x;
        } else if (x > m2 && x < m) {
            m2 = x;
        }
        s.insert(x);
        cout << b << " ";
    }
    cout << ln;
}
signed main() {
    docfile();
    fastio();

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
    time();
    return 0;
}