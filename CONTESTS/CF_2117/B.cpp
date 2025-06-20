// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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
    
    vector<int> evens, odds;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) evens.push_back(i);
        else odds.push_back(i);
    }
    
    reverse(odds.begin(), odds.end());
    
    vector<int> vec;
    vec.insert(vec.end(), evens.begin(), evens.end());
    vec.insert(vec.end(), odds.begin(), odds.end());
    
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) cout << " ";
    }

    cout << ln;
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