// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/78

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
    
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }
    
    ll res = 0;
    for (int left = 0; left < n; ++left) {
        int lo = left, hi = n - 1;
        int min_right = n;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix_sum[mid + 1] - prefix_sum[left] >= k) {
                min_right = mid;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }
        
        if (min_right < n) {
            res += n - min_right;
        }
    }

    cout << res << ln;

    time();
    return 0;
}