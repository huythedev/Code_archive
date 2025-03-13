// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/1399/A
// davul
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

bool canRearrange(vector<int>& a) {
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] - a[i - 1] > 1) {
            return false;
        }
    }
    return true;
}

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (canRearrange(a)) {
            cout << "YES" << ln;
        } else {
            cout << "NO" << ln;
        }
    }

    time();
    return 0;
}