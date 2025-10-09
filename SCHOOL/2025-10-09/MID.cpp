// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MID"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
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
    vector<int> a(n);
    int maxA = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }

    vector<int> freq(maxA + 1, 0);
    for (int x : a) freq[x]++;

    int countMid = 0;
    
    for (int v = 1; v <= maxA; ++v) {
        if (!freq[v]) continue;
        bool ok = false;
        
        int L = 1, R = maxA;
        int target = 2 * v;
        while (L <= R) {
            int sum = L + R;
            if (sum == target) {
                if ((L != R && freq[L] && freq[R]) ||
                    (L == R && freq[L] > 1)) {
                    ok = true;
                    break;
                }
                ++L; --R;
            } else if (sum < target)
                ++L;
            else
                --R;
        }
        if (ok) countMid += freq[v];
    }

    cout << countMid;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}