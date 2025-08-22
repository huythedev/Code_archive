// Author: huythedev
// Problem Link: 
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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        int tmp = c / a[i];

        if(tmp == 0) {
            vec[i] = -1;
        } 
        else {
            int ld = 63 - __builtin_clzll(tmp);
            vec[i] = ld;
        }
    }

    sort(vec.begin(), vec.end());

    set<int> st;
    for (int i = 0; i < n; i++) 
        st.insert(i);

    int tmp = 0;
    for (int m : vec) {
        if (!st.empty()) {
            auto it = st.begin();
            
            if (*it <= m) {
                st.erase(it);
                tmp++;
            }
        }
    }

    cout << n - tmp << ln;
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