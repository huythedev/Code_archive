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
    int n, m; 
        cin >> n >> m;
        vector<string> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];

        // B = 180-degree rotation of A
        vector<string> B = A;
        reverse(B.begin(), B.end());
        for (auto &row : B) reverse(row.begin(), row.end());

        Hash2D HA(A), HB(B);

        ll best = (ll)4e18; // big
        // iterate all possible sums (centers) Sr in [2..2n], Sc in [2..2m]
        for (int Sr = 2; Sr <= 2*n; ++Sr) {
            int ia_lo = max(1, Sr - n);
            int ia_hi = min(n, Sr - 1);
            int h = ia_hi - ia_lo + 1;
            int dx = abs(Sr - (n + 1));

            for (int Sc = 2; Sc <= 2*m; ++Sc) {
                int ja_lo = max(1, Sc - m);
                int ja_hi = min(m, Sc - 1);
                int w = ja_hi - ja_lo + 1;
                int dy = abs(Sc - (m + 1));

                // corresponding top-left in B
                int r0 = (n + 1 - Sr) + ia_lo;
                int c0 = (m + 1 - Sc) + ja_lo;

                // compare overlapped rectangles
                auto hA = HA.get(ia_lo, ja_lo, h, w);
                auto hB = HB.get(r0, c0, h, w);
                if (hA == hB) {
                    ll add = (ll)n * dy + (ll)m * dx + (ll)dx * dy; // (n+dx)*(m+dy) - n*m
                    if (add < best) best = add;
                }
            }
        }

        cout << best << ln;
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