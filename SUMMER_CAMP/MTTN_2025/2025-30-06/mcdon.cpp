// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "mcdon"
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
struct Trie {
    struct Node {
        int child[2];
        int64_t sum;
        Node() { child[0]=child[1]=-1; sum=0; }
    };
    vector<Node> t;
    Trie() { t.reserve(100000*32/2); t.emplace_back(); }
    void insert(int x, int v) {
        int u = 0;
        t[u].sum = (t[u].sum + v) % MOD;
        for (int b = 30; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (t[u].child[bit] == -1) {
                t[u].child[bit] = t.size();
                t.emplace_back();
            }
            u = t[u].child[bit];
            t[u].sum = (t[u].sum + v) % MOD;
        }
    }
    int64_t query_le(int s, int K) {
        int u = 0;
        int64_t res = 0;
        for (int b = 30; b >= 0; --b) {
            if (u == -1) break;
            int sb = (s >> b) & 1;
            int kb = (K >> b) & 1;
            if (kb == 1) {
                int c = t[u].child[sb];
                if (c != -1) res = (res + t[c].sum) % MOD;
                u = t[u].child[sb^1];
            } else {
                u = t[u].child[sb];
            }
        }
        if (u != -1) res = (res + t[u].sum) % MOD;
        return res;
    }
};
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), L(k+1), R(k+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) cin >> L[i] >> R[i];
 
    vector<int> P(n+1,0);
    for(int i=1;i<=n;i++) P[i] = P[i-1] ^ a[i];
 
    vector<int> dp_prev(n+1,0), dp_cur(n+1,0);
    dp_prev[0] = 1; 
 
    for(int i=1;i<=k;i++){
        Trie trie;
        trie.insert(P[0], dp_prev[0]);
        for(int j=1;j<=n;j++){
            int64_t sum_r = trie.query_le(P[j], R[i]);
            int64_t sum_lm1 = (L[i]>0 ? trie.query_le(P[j], L[i]-1) : 0);
            dp_cur[j] = (int)((sum_r - sum_lm1 + MOD) % MOD);
            trie.insert(P[j], dp_prev[j]);
        }
        dp_prev.swap(dp_cur);
        fill(dp_cur.begin(), dp_cur.end(), 0);
    }
 
    cout << dp_prev[n] << ln;
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