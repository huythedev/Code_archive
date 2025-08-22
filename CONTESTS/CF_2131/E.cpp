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

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n), b(n), pref(n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i) 
        cin >> b[i];

    if (a[n - 1] != b[n - 1]) {
        cout << "NO" << ln;
        return;
    }

    pref[0] = a[0];
    for (int i = 1; i < n; ++i) 
        pref[i] = pref[i - 1] ^ a[i];

    vector<int> vec(n, 0);
    vec[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        if (b[i] == a[i]) {
            vec[i] = i;
            continue;
        }

        if ((a[i] ^ a[i + 1]) == b[i]) {
            vec[i] = i + 1;
            continue;
        }

        int R = vec[i + 1];
        if (R < n) {
            int suf = pref[R] ^ pref[i];
            if ((a[i] ^ suf) == b[i]) {
                vec[i] = R;
                continue;
            }
        }

        cout << "NO" << ln;
        return;
    }

    cout << "YES" << ln;
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