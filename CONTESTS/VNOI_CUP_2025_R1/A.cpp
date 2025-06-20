// Author: huythedev
// Problem Link:
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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
    string s;
    cin >> s;
    int n = s.sz;
    vector<int> preU(n + 1, 0), preI(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preU[i + 1] = preU[i] + (s[i] == 'U');
        preI[i + 1] = preI[i] + (s[i] == 'I');
    }
    vector<ll> min1(n + 1, 0), min2(n + 1, 0);
    vector<int> argmin1(n + 1, 0), argmin2(n + 1, 0);
    min1[0] = preU[0] - 2LL * preI[0];
    min2[0] = preI[0] - 2LL * preU[0];
    for (int m = 1; m <= n; m++) {
        ll val1 = preU[m] - 2LL * preI[m];
        ll val2 = preI[m] - 2LL * preU[m];
        min1[m] = min(min1[m - 1], val1);
        argmin1[m] = (val1 < min1[m - 1]) ? m : argmin1[m - 1];
        min2[m] = min(min2[m - 1], val2);
        argmin2[m] = (val2 < min2[m - 1]) ? m : argmin2[m - 1];
    }
    bool found = false;
    for (int r = 0; r < n && !found; r++) {
        int k = -1;
        while (k + 1 < r && preU[k + 1] <= preU[r + 1] - 1 && preI[k + 1] <= preI[r + 1] - 1) {
            k++;
        }
        if (k >= 0) {
            ll target1 = preU[r + 1] - 2LL * preI[r + 1];
            ll target2 = preI[r + 1] - 2LL * preU[r + 1];
            int l1 = argmin1[k];
            int cntu1 = preU[r + 1] - preU[l1];
            int cnti1 = preI[r + 1] - preI[l1];
            if (min1[k] <= target1 && cntu1 >= 1 && cnti1 >= 1) {
                cout << "Yes " << l1 + 1 << " " << r + 1 << ln;
                found = true;
            }
            if (!found) {
                int l2 = argmin2[k];
                int cntu2 = preU[r + 1] - preU[l2];
                int cnti2 = preI[r + 1] - preI[l2];
                if (min2[k] <= target2 && cntu2 >= 1 && cnti2 >= 1) {
                    cout << "Yes " << l2 + 1 << " " << r + 1 << ln;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "No" << ln;
    }
}

signed main() {
    fastio();
    docfile();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}