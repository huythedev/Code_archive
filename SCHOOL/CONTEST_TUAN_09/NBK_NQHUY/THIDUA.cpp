// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "THIDUA"
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

signed main() {
    fastio();
    docfile();

    string s; cin >> s;

    map<pair<int, int>, int> freq;
    freq[{0, 0}] = 1;

    int prefix_N = 0, prefix_A = 0, prefix_M = 0;
    ll res = 0;

    for (char c : s) {
        if (c == 'N') ++prefix_N;
        else if (c == 'A') ++prefix_A;
        else if (c == 'M') ++prefix_M;
        
        pair<int, int> curr = {prefix_N - prefix_A, prefix_N - prefix_M};
        
        if (freq.count(curr)) {
            res += freq[curr];
        }
        
        freq[curr]++;
    }

    cout << res << ln;

    time();
    return 0;
}
