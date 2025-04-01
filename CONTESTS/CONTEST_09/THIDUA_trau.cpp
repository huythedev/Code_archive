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

const int maxn = 1e6;

string st;
vector<map<char, int>> freq;

void pre_calc() {
    map<char, int> curr;
    freq.resize(st.sz + 1);
    freq[0] = curr;
    for (int i = 0; i < (int)st.sz; ++i) {
        curr[st[i]]++;
        freq[i+1] = curr;
    }
}

void solve() {
    int n = (int)st.sz;
    ll res = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int countN = freq[j+1]['N'] - freq[i]['N'];
            int countA = freq[j+1]['A'] - freq[i]['A'];
            int countM = freq[j+1]['M'] - freq[i]['M'];
            
            if (countN == countA && countA == countM && countN > 0) {
                ++res;
            }
        }
    }
    
    cout << res << ln;
}

signed main() {
    fastio();
    docfile();

    cin >> st;
    pre_calc();
    solve();

    time();
    return 0;
}