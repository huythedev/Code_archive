// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> A(n + 1), B(m + 1);
    for (int i = 1; i <= n; ++i) 
        cin >> A[i];
    for (int i = 1; i <= m; ++i) 
        cin >> B[i];

    sort(A.begin() + 1, A.begin() + n + 1, greater<ll>());
    sort(B.begin() + 1, B.begin() + m + 1, greater<ll>());

    vector<ll> prefixSumA(n + 1, 0), prefixSumB(m + 1, 0);
    for (int i = 1; i <= n; ++i) 
        prefixSumA[i] = prefixSumA[i - 1] + A[i];
    for (int i = 1; i <= m; ++i) 
        prefixSumB[i] = prefixSumB[i - 1] + B[i];

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int l = max(0, z - y), r = min(z, x);
        
        if (z == 0) { 
            cout << 0 << ln; 
            continue; 
        }

        if (l == r) {
            cout << prefixSumA[l] + prefixSumB[z - l] << ln;
            continue;
        }
        
        r--;
        int tmp = l - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;

            if (A[mid + 1] >= B[z - mid]) {
                tmp = mid;
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }

        int k = max(tmp + 1, l);
        cout << prefixSumA[k] + prefixSumB[z - k] << ln;
    }
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}