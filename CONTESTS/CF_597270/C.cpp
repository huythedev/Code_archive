// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/597270/problem/C
// davul
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

const int MOD = 1000000007;
const int OFFSET = 40000;
const int MAX_S = 80001;

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        int n, a; cin >> n >> a;
        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
            y[i] -= a;
        }
        vector<int> prev(MAX_S, 0);
        prev[OFFSET] = 1;
        for (int i = 0; i < n; ++i) {
            vector<int> curr = prev;
            for (int s = 0; s < MAX_S; ++s) {
                if (s - y[i] >= 0 && s - y[i] < MAX_S) {
                    curr[s] = (curr[s] + prev[s - y[i]]) % MOD;
                }
            }
            prev = curr;
        }
        cout << (prev[OFFSET] - 1 + MOD) % MOD << ln;
    }

    time();
    return 0;
}