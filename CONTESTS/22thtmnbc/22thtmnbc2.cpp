// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc2
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc2"
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

int getRichness(int l, int r, const vector<int>& c) {
    bitset<64> provinces; 
    for (int i = l; i <= r; i++) {
        provinces.set(c[i]);
    }
    return provinces.count();
}

int main() {
    fastio();
    docfile();

    int n, g;
    cin >> n >> g;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    if (g == 2) {
        vector<int> left(n);
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            seen.insert(c[i]);
            left[i] = seen.size();
        }
        
        vector<int> right(n);
        seen.clear();
        for (int i = n - 1; i >= 0; i--) {
            seen.insert(c[i]);
            right[i] = seen.size();
        }
        
        int answer = 0;
        for (int i = 0; i < n - 1; i++) {
            answer = max(answer, left[i] + right[i + 1]);
        }
        
        cout << answer << ln;
        time();
        return 0;
    }
    
    if (g == 3) {
        vector<unordered_set<int>> prefixSets(n + 1);
        vector<int> prefixCount(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefixSets[i + 1] = prefixSets[i];
            prefixSets[i + 1].insert(c[i]);
            prefixCount[i + 1] = prefixSets[i + 1].size();
        }
        
        int answer = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int richness1 = prefixCount[i];
                
                unordered_set<int> group2;
                for (int k = i; k < j; k++) {
                    group2.insert(c[k]);
                }
                int richness2 = group2.size();
                
                unordered_set<int> group3;
                for (int k = j; k < n; k++) {
                    group3.insert(c[k]);
                }
                int richness3 = group3.size();
                
                answer = max(answer, richness1 + richness2 + richness3);
            }
        }
        
        cout << answer << ln;
        time();
        return 0;
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(g + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        dp[i][1] = getRichness(0, i - 1, c);
    }
    
    for (int j = 2; j <= g; j++) {
        for (int i = j; i <= n; i++) {
            dp[i][j] = 0; 
            for (int k = j - 1; k < i; k++) {
                int currRichness = getRichness(k, i - 1, c);
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + currRichness);
            }
        }
    }
    
    cout << dp[n][g] << ln;

    time();
    return 0;
}