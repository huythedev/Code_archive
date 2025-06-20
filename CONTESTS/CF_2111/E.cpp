// Author: huythedev
// Problem Link: https://codeforces.com/contest/2111/problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    vector<char> X(q + 1), Y(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> X[i] >> Y[i];
    }
    
    vector<int> A;
    set<int> B;
    vector<int> C;
    vector<int> D;
    for (int i = 1; i <= q; i++) {
        if (X[i] == 'b' && Y[i] == 'a') A.push_back(i);
        else if (X[i] == 'c' && Y[i] == 'a') B.insert(i);
        else if (X[i] == 'b' && Y[i] == 'c') C.push_back(i);
        else if (X[i] == 'c' && Y[i] == 'b') D.push_back(i);
    }

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    
    vector<int> vec(q + 1, -1);
    int a2 = 0, c2 = 0, d2 = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') continue;
        if (s[i] == 'b') {
            if (a2 < (int)A.sz) {
                vec[A[a2]] = i;
                a2++;
            } else if (c2 < (int)C.sz && !B.empty()) {
                int k1 = C[c2];
                int k2 = *B.begin();

                if (k1 < k2) {
                    vec[k1] = i;
                    vec[k2] = i;
                    c2++;
                    B.erase(k2);
                }
            }
        } else if (s[i] == 'c') {
            if (!B.empty()) {
                int k = *B.begin();
                vec[k] = i;
                B.erase(k);
            } else if (d2 < (int)D.sz) {
                if (a2 < (int)A.sz) {
                    int k1 = D[d2];

                    auto it = lower_bound(A.begin() + a2, A.end(), k1 + 1);
                    if (it != A.end()) {
                        int k2 = *it;
                        vec[k1] = i;
                        vec[k2] = i;
                        d2++;
                        a2 = it - A.begin() + 1;
                    } else {
                        vec[D[d2]] = i;
                        d2++;
                    }
                } else {
                    vec[D[d2]] = i;
                    d2++;
                }
            }
        }
    }
    
    for (int k = 1; k <= q; k++) {
        if (vec[k] != -1) {
            int i = vec[k];
            if (s[i] == X[k]) {
                s[i] = Y[k];
            }
        }
    }
    
    cout << s << ln;
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