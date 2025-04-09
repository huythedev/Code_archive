// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2075/problem/C
// davul
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

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        
        vector<int> a(m);
        map<int, int> freq;

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> vec(n + 2, 0);
        for (int i = n; i >= 1; i--) vec[i] = freq[i] + vec[i + 1];

        ll res = 0;
        for (int i = 1; i < n; i++) {
            int l = vec[i], r = vec[n - i], tmp = vec[max(i, n - i)];
            res += static_cast<ll>(l) * r - tmp;
        }

        cout << res << ln;
    }

    time();
    return 0;
}