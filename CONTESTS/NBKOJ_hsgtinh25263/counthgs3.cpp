// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "counthgs3"
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

void subtask2(int n, int k, const vector<int> &a) {
    int S = k * (k + 1) / 2;
    if (S > n) {
        cout << 0 << ln;
        return;
    }

    vector<int> freq(k + 1, 0), vec(k + 1, 0);
    
    for (int i = 0; i < S; ++i) {
        if (1 <= freq[a[i]] && freq[a[i]] <= k) 
            --vec[freq[a[i]]];

        ++freq[a[i]];

        if (1 <= freq[a[i]] && freq[a[i]] <= k) 
            ++vec[freq[a[i]]];
    }

    ll ans = 0;
    bool ok = true;
    for (int i = 1; i <= k; ++i) {
        if (vec[i] != 1) { 
            ok = false; 
            break; 
        }
    }

    if (ok) 
        ++ans;

    for (int l = 0, r = S; r < n; ++l, ++r) {
        if (1 <= freq[a[l]] && freq[a[l]] <= k) 
            --vec[freq[a[l]]];

        --freq[a[l]];

        if (1 <= freq[a[l]] && freq[a[l]] <= k) 
            ++vec[freq[a[l]]];

        if (1 <= freq[a[r]] && freq[a[r]] <= k) 
            --vec[freq[a[r]]];

        ++freq[a[r]];

        if (1 <= freq[a[r]] && freq[a[r]] <= k) 
            ++vec[freq[a[r]]];

        ok = true;

        for (int t = 1; t <= k; ++t) {
            if (vec[t] != 1) { 
                ok = false; 
                break; 
            }
        }

        if (ok) 
            ++ans;
    }

    cout << ans << ln;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    bool sub2 = true;
    for (int &x : a) {
        cin >> x;
        if (x < 1 || x > k)
            sub2 = false;
    }

    if (k == 1) {
        cout << (ll)n * (n + 1) / 2 << ln;
        return;
    }

    if (sub2) {
        subtask2(n, k, a);
        return;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> freq;
        vector<int> vec(k + 1, 0);

        for (int j = i; j < n; ++j) {
            if (freq[a[j]] >= 1 && freq[a[j]] <= k) 
                --vec[freq[a[j]]];

            ++freq[a[j]];
            if (freq[a[j]] >= 1 && freq[a[j]] <= k) 
                ++vec[freq[a[j]]];

            bool ok = true;
            for (int t = 1; t <= k; ++t) {
                if (vec[t] == 0) { 
                    ok = false; 
                    break; 
                }
            }

            if (ok) 
                ++ans;
        }
    }

    cout << ans << ln;
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