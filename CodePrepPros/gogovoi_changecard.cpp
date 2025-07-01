// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_changecard"
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
    int n, k; cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    
    vector<int> freq(50101, 0);
    for (int i = 0; i < n; ++i)
        freq[c[i]]++;
    
    int nextVal = 101;
    while (true) {
        int max_freq = 0;
        int v = -1;
        for (int i = 0; i < (int)freq.size(); ++i) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                v = i;
            }
        }

        if (max_freq < k)
            break;
        
        freq[v] -= k;
        if (freq[v] < 0) 
            freq[v] = 0;

        int tmp = 0;
        int w = -1;
        for (int i = 0; i < (int)freq.size(); ++i) {
            if (freq[i] < k && freq[i] > tmp) {
                tmp = freq[i];
                w = i;
            }
        }

        if (w != -1) {
            freq[w] += (k - 1);
        }
        else {
            for (int i = 0; i < k - 1; ++i) {
                freq[nextVal] = 1;
                nextVal++;
            }
        }
    }
    
    int res = 0;
    for (int i : freq)
        res += i;

    cout << res << ln;
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