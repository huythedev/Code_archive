// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MATCHING"
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
    int n, m;
    cin >> n >> m;
    vector<int> S(n + 1), A(m + 1);
    for (int i = 1; i <= n; ++i) cin >> S[i];
    for (int i = 1; i <= m; ++i) cin >> A[i];

    vector<int> L(n + 1, 0), R(n + 1, 0);
    vector<int> posVal(n + 1, 0);
    set<int> seen;

    for (int i = 1; i <= n; ++i) {
        auto itPred = seen.lower_bound(S[i]);
        if (itPred != seen.begin()) {
            --itPred;
            L[i] = posVal[*itPred];
        }
        auto itSucc = seen.upper_bound(S[i]);
        if (itSucc != seen.end()) {
            R[i] = posVal[*itSucc];
        }
        seen.insert(S[i]);
        posVal[S[i]] = i;
    }

    auto ok = [&](const vector<int>& T, int i, int q) -> bool {
        int base = i - q - 1;
        
        int li = L[q + 1];
        if (li && !(T[base + li] < T[i])) 
            return false;
        
        int ri = R[q + 1];
        if (ri && !(T[i] < T[base + ri])) 
            return false;
        
        return true;
    };

    vector<int> pi(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        int q = pi[i - 1];

        while (q > 0 && !ok(S, i, q)) 
            q = pi[q];

        if (ok(S, i, q)) 
            ++q;
        
        pi[i] = q;
    }

    vector<int> ans;
    int q = 0;
    for (int i = 1; i <= m; ++i) {
        while (q > 0 && !ok(A, i, q)) 
            q = pi[q];
        
        if (ok(A, i, q)) 
            ++q;
        
        if (q == n) {
            ans.push_back(i - n + 1); 
            q = pi[q];
        }
    }

    cout << (int)ans.size() << ln;
    for (int &x : ans) cout << x << ' ';
    cout << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}