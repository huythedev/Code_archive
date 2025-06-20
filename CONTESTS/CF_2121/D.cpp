// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
#define ln "\n"
#define sz size ()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);
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

void solve () {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    
    vector<pair<int, int>> ops;
    while (true) {
        bool swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ops.push_back({1, i + 1});
                swapped = true;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (b[i] > b[i + 1]) {
                swap(b[i], b[i + 1]);
                ops.push_back({2, i + 1});
                swapped = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if(a[i] > b[i]) {
                swap(a[i], b[i]);
                ops.push_back({3, i + 1});
                swapped = true;
            }
        }
        
        if (!swapped) 
            break;
    }
    
    cout << ops.sz << ln;
    for (auto i : ops) {
        cout << i.first << " " << i.second << ln;
    }
}

signed main() {
    docfile ();
    fastio ();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time ();
    return 0;
}