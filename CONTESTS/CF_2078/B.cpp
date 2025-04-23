// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2078/problem/B

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

signed main() {
    fastio();
    docfile();
    
    int t; cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        vector<int> vec(n + 1);
        
        if (k % 2 == 1) {
            // For odd k, create a cycle from 1->2->...->n->1
            for (int i = 1; i <= n - 1; i++) {
                vec[i] = i + 1;
            }
            vec[n] = 1;
        }
        else {
            // For even k
            if (n == 2) {
                vec[1] = 2;
                vec[2] = 1;
            }
            else {
                // For cells 1 to n-1, point to n (exit)
                for (int i = 1; i < n; i++) {
                    vec[i] = n;
                }
                // Exit points to any non-exit cell, we'll use n-1
                vec[n] = n - 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << vec[i] << (i == n ? ln : " ");
        }
    }

    time();
    return 0;
}