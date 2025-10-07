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
    int n, k;
    string s;
    cin >> n >> k >> s;

    bool tmp = false;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') 
            ++cnt;
        
        if (i >= k && s[i - k] == '1') 
            --cnt;
        
        if (i >= k - 1 && cnt == k) {
            tmp = true;
            break;
        }
    }

    if (tmp) {
        cout << "NO" << ln;
        return;
    }

    cout << "YES" << ln;
    vector<int> vec(n);
    int curr = n;

    for (int i = 0; i < n; ++i)
        if (s[i] == '0') 
            vec[i] = curr--;
    
    for (int i = 0; i < n; ++i)
        if (s[i] == '1') 
            vec[i] = curr--;
    
    for (int i = 0; i < n; ++i)
        cout << vec[i] << ' ';

    cout << ln;
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