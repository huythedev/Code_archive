// Author: huythedev
// Problem Link: https://marisaoj.com/problem/430
#include <bits/stdc++.h>
using namespace std;
 
#define NAME "430"
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
    if (n == 1) {
        cout << "YES" << ln;
        return;
    }
    vector<int> A(n);
    for (int &x : A) cin >> x;
 
    bool isBitonic = true;
    string state = "increasing";
 
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] == A[i + 1]) {
            isBitonic = false;
            break;
        }
        if (state == "increasing") {
            if (A[i] > A[i + 1]) {
                state = "decreasing";
            }
        } else if (state == "decreasing") {
            if (A[i] < A[i + 1]) {
                isBitonic = false;
                break;
            }
        }
    }
 
    if (isBitonic) cout << "YES" << ln;
    else cout << "NO" << ln;
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