// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> last(n + 1, -1);
    for (int i = 0; i < n; ++i)
        last[a[i]] = i;

    vector<int> freq(n + 1, 0);
    vector<bool> vec2(n + 1, false);
    int cnt = 0, l = 0, need = 0, tmp = 0;
    int active = 0;
    int at_last = 0;
    int lastmin = n;

    for (int r = 0; r < n; ++r) {
        int x = a[r];
        freq[x]++;

        if (freq[x] == 1) {
            active++;
            if (last[x] == r) at_last++;
            if (vec2[x]) tmp++;
        }
        lastmin = (active > at_last) ? r + 1 : r;

        if (tmp == need && (r == n - 1 || lastmin > r)) {
            cnt++;
            if (r < n - 1) {
                vec2.assign(n + 1, false);
                need = 0;

                for (int i = l; i <= r; ++i) {
                    if (freq[a[i]] > 0 && !vec2[a[i]]) {
                        vec2[a[i]] = true;
                        need++;
                    }
                }

                for (int i = l; i <= r; ++i) {
                    freq[a[i]] = 0;
                }

                active = 0;
                at_last = 0;
                tmp = 0;
            }
            l = r + 1;
        }
    }

    cout << cnt << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}