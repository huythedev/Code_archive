// Author: huythedev (https://huythedev.com)
// Problem Link: 

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
vector<int> prefN, prefA, prefM;

void pre_calc() {
    int n = (int)st.sz;
    prefN.resize(n + 1);
    prefA.resize(n + 1);
    prefM.resize(n + 1);
    
    for (int i = 0; i < n; i++) {
        prefN[i+1] = prefN[i] + (st[i] == 'N');
        prefA[i+1] = prefA[i] + (st[i] == 'A');
        prefM[i+1] = prefM[i] + (st[i] == 'M');
    }
}

void solve() {
    int n = (int)st.sz;
    ll res = 0;
    
    const int OFFSET = maxn + 10; 
    unordered_map<ll, int> seen;
    seen.reserve(2 * n);
    seen[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        int diffNA = prefN[i] - prefA[i];
        int diffNM = prefN[i] - prefM[i];
        
        ll key = (ll)(diffNA + OFFSET) * (2 * OFFSET) + (diffNM + OFFSET);
        
        if (seen.count(key)) {
            res += seen[key];
        }
        
        seen[key]++;
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