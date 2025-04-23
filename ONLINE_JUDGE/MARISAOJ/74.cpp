// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/74

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

    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end()); 
    
    int l = 0, r = n - 1;
    int res = 0;
    
    while (l <= r) {
        if (l == r) {
            ++res;
            break;
        }
        
        if (A[l] + A[r] <= k) {
            ++res;
            ++l;
            --r;
        } 
        else {
            ++res;
            --r;
        }
    }

    cout << res << ln;

    time();
    return 0;
}