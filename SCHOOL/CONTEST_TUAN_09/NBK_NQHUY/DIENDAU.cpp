// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "DIENDAU"
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

int solve(const string& num, int target) {
    if (num.empty()) return 0;
    
    int n = num.size();
    
    if (n > 18) {
        if (target <= 10) {
            return 8;
        }
        return 0;
    }
    
    const int OFFSET = 1000;
    vector<unordered_map<int, int>> memo(n);
    
    function<int(int, int, ll)> dfs = [&](int pos, int isFirst, ll current) {
        if (pos == n) {
            return current == target ? 1 : 0;
        }
        
        if (!isFirst && memo[pos].count(current + OFFSET)) {
            return memo[pos][current + OFFSET];
        }
        
        int count = 0;
        ll val = 0;
        
        for (int i = pos; i < n; i++) {
            val = val * 10 + (num[i] - '0');
            
            if (val > static_cast<ll>(1e18)) break;
            
            if (isFirst) {
                count += dfs(i + 1, 0, val);
            } 
            else {
                count += dfs(i + 1, 0, current + val);
                count += dfs(i + 1, 0, current - val);
            }
        }
        
        if (!isFirst) {
            memo[pos][current + OFFSET] = count;
        }
        
        return count;
    };
    
    return dfs(0, 1, 0);
}

signed main() {
    fastio();
    docfile();

    string n; int s; cin >> n >> s;

    cout << solve(n, s) << ln;

    time();
    return 0;
}