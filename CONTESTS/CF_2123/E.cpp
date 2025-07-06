// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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
    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> diff(n + 2, 0);

    int tmp = 0;
    while (tmp <= n && freq[tmp] > 0) {
        tmp++;
    }

    for (int m = 0; m < tmp; ++m) {
        int k1 = freq[m], k2 = n - m;
        if (k1 <= k2) {
            diff[k1]++;
            diff[k2 + 1]--;
        }
    }

    if (tmp <= n) {
        int k1 = 0, k2 = n - tmp;
        if (k1 <= k2) {
            diff[k1]++;
            diff[k2 + 1]--;
        }
    }

    int curr = 0;
    for (int k = 0; k <= n; ++k) {
        curr += diff[k];
        cout << curr << " ";
    }

    cout << ln;
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