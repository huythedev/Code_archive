// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "76"
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
    int n, q; cin >> n >> q;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    while (q--) {
        int x; cin >> x;

        int l = 0, r = n - 1;
        int mid = (l + r) / 2;
        int pos = -1;
        bool found = false;
        while (l < r) {
            if (A[mid] == x) {
                pos = mid;
                found = true;
                break;
            }
            if (A[mid] > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }

        if (!found && A[l] != x) {
            cout << "-1" << ln;
            continue;
        }

        if (pos == -1) pos = l;

        while (pos > 0 && A[pos - 1] == A[pos]) pos--;

        cout << pos + 1 << ln;
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