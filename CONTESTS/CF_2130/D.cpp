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

void solve() { 
    int n; 
    cin >> n; 
    vector<int> p(n); 
    for (int i = 0; i < n; ++i) { 
        cin >> p[i]; 
    } 

    ll res = 0; 
    for (int i = 0; i < n; ++i) { 
        for (int j = i + 1; j < n; ++j) { 
            if (p[i] > p[j]) { 
                res++; 
            } 
        } 
    } 

    for (int i = 0; i < n; ++i) { 
        ll tmp = 0; 
        
        ll tmp2 = 0; 
        for (int j = i + 1; j < n; ++j) { 
            if (p[i] > p[j]) { 
                tmp2++; 
            } 
        } 
        
        ll tmp3 = 0; 
        for (int j = 0; j < i; ++j) { 
            if (p[j] > p[i]) { 
                tmp3++; 
            } 
        } 
        
        tmp = (n - 1 - i) - tmp2 - tmp3; 

        if (tmp < 0) { 
            res += tmp; 
        } 
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