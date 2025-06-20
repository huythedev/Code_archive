// Author: huythedev
// Problem Link: https://marisaoj.com/problem/30
#include <bits/stdc++.h>
using namespace std;

#define NAME "30"
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

    vector<ll> nums(51);
    nums[1] = 1;
    nums[2] = 1;
    
    if (n >= 1) {
        cout << 1 << ln;
    }
    if (n >= 2) {
        cout << "1 1" << ln;
    }
    
    if (n > 2) {
        for (int i = 3; i <= n; ++i) {
            vector<ll> newvec = nums;
            newvec[1] = 1;
            newvec[i] = 1;

            cout << 1 << ' ';
            for (int j = 2; j < i; ++j) {
                newvec[j] = nums[j - 1] + nums[j];
                cout << newvec[j] << ' ';
            }

            cout << 1 << ln;
            nums = newvec;
        }
    }
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