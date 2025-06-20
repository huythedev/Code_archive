// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

const int MOD = 1e9 + 7;
const int LIM = 200000;
const int SZ_LIM = 2 * LIM + 5;


vector<vector<int>> adj;

struct State {
    bitset<SZ_LIM> sums; 
    int root_sum;
    ll ways;
};

vector<vector<State>> dp;

bool cmp(const State& a, const State& b) {
    if (a.root_sum != b.root_sum) {
        return a.root_sum < b.root_sum;
    }
    for (int i = SZ_LIM - 1; i >= 0; --i) {
        if (a.sums[i] != b.sums[i]) {
            return !a.sums[i] && b.sums[i]; 
        }
    }
    return false; 
}

void dfs(int u, int p) {
    vector<int> children;
    for (int v : adj[u]) {
        if (v != p) {
            children.push_back(v);
        }
    }
    
    if (children.empty()) {
        State s1, s2;
        s1.sums[1] = 1; 
        s1.root_sum = 1; 
        s1.ways = 1;
        dp[u].push_back(s1);
        
        s2.sums[2] = 1; 
        s2.root_sum = 2; 
        s2.ways = 1;
        dp[u].push_back(s2);
        return;
    }
    
    for (int i : children) {
        dfs(i, u);
    }
    vector<vector<int>> vec;
    vector<int> curr;
    
    function<void(int)> gen = [&](int idx) {
        if (idx == (int)children.size()) {
            vec.push_back(curr);
            return;
        }

        for (int i = 0; i < (int)dp[children[idx]].size(); ++i) {
            curr.push_back(i);
            gen(idx + 1);
            curr.pop_back();
        }
    };
    
    gen(0);
    
    for (auto& x : vec) {
        bitset<SZ_LIM> bs;
        ll curr_ways = 1;
        int sum = 0;
        bool ok = true;
        
        for (int i = 0; i < (int)children.size(); ++i) {
            int node = children[i];
            int idx = x[i];
            const State& tmp = dp[node][idx];
            
            if ((bs & tmp.sums).any()) {
                ok = false;
                break;
            }
            bs |= tmp.sums;
            curr_ways = (curr_ways * tmp.ways) % MOD;
            sum += tmp.root_sum;
        }
        
        if (!ok) continue;
        
        for (int i = 1; i <= 2; ++i) {
            int tmp = i + sum;
            
            if (tmp >= SZ_LIM) continue;

            if (!bs[tmp]) { 
                State newstate;
                newstate.sums = bs;
                newstate.sums[tmp] = 1;
                newstate.root_sum = tmp;
                newstate.ways = curr_ways;
                dp[u].push_back(newstate);
            }
        }
    }

    if (!dp[u].empty()) {
        sort(dp[u].begin(), dp[u].end(), cmp);
        
        vector<State> merged;
        merged.push_back(dp[u][0]);
        
        for (size_t i = 1; i < dp[u].size(); ++i) {
            if (dp[u][i].root_sum == merged.back().root_sum && dp[u][i].sums == merged.back().sums) {
                merged.back().ways = (merged.back().ways + dp[u][i].ways) % MOD;
            } else {
                merged.push_back(dp[u][i]);
            }
        }

        dp[u] = merged;
    }
}

void solve() {
    cin >> n;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        leaves.clear();
        findLeaves(1, -1);
        int leafCount = leaves.size();

        if (leafCount > 2) {
            cout << 0 << endl;
        } else if (leafCount == 1) {
            cout << power(2, n) << endl;
        } else {
            int u = leaves[0], v = leaves[1];
            long long ans = 0;
            for (int au = 1; au <= 2; au++) {
                for (int av = 1; av <= 2; av++) {
                    if (au != av) {
                        bitset<MAX_SUM> sumU, sumV;
                        int currentU = 0, currentV = 0;
                        computeSums(u, -1, au, sumU, currentU);
                        computeSums(v, -1, av, sumV, currentV);
                        if ((sumU & sumV).none()) {
                            long long waysU = countWays(u, -1, au);
                            long long waysV = countWays(v, -1, av);
                            ans = (ans + waysU * waysV % MOD) % MOD;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
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