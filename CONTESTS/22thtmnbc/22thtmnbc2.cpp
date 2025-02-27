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
        vector<int> prefixRichness(n);
        bitset<64> prefixProvinces;
        for (int i = 0; i < n; i++) {
            prefixProvinces.set(c[i]);
            prefixRichness[i] = prefixProvinces.count();
        }
        
        vector<int> suffixRichness(n);
        bitset<64> suffixProvinces;
        for (int i = n - 1; i >= 0; i--) {
            suffixProvinces.set(c[i]);
            suffixRichness[i] = suffixProvinces.count();
        }
        
        int answer = 0;
        for (int i = 0; i < n - 1; i++) {
            answer = max(answer, prefixRichness[i] + suffixRichness[i + 1]);
        }
        
        cout << answer << ln;
        return 0;
    }
    
    if (g == 3) {
        vector<int> prefixRichness(n + 1, 0);
        bitset<64> prefixProvinces;
        for (int i = 0; i < n; i++) {
            prefixProvinces.set(c[i]);
            prefixRichness[i + 1] = prefixProvinces.count();
        }
        
        int answer = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int richness1 = prefixRichness[i]; 
            
            // For each possible second split
            bitset<64> middleProvinces;
            for (int j = i; j < n - 1; j++) {
                middleProvinces.set(c[j]);
                int richness2 = middleProvinces.count(); 
                
                bitset<64> lastProvinces;
                for (int k = j + 1; k < n; k++) {
                    lastProvinces.set(c[k]);
                }
                int richness3 = lastProvinces.count(); 
                
                answer = max(answer, richness1 + richness2 + richness3);
            }
        }
        
        cout << answer << ln;
        return 0;
    }
    
    if (n <= 100) {
        vector<vector<int>> richness(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            bitset<64> provinces;
            for (int r = l; r < n; r++) {
                provinces.set(c[r]);
                richness[l][r] = provinces.count();
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(g + 1, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][1] = richness[0][i];
        }
        
        for (int j = 2; j <= g; j++) {
            for (int i = j - 1; i < n; i++) {
                for (int k = j - 2; k < i; k++) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + richness[k + 1][i]);
                }
            }
        }
        
        cout << dp[n - 1][g] << ln;
    } 
    else {
        int answer = 0;
        if (g == 4) {
            for (int i = 1; i < n - 2; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        bitset<64> g1, g2, g3, g4;
                        for (int x = 0; x < i; x++) g1.set(c[x]);
                        for (int x = i; x < j; x++) g2.set(c[x]);
                        for (int x = j; x < k; x++) g3.set(c[x]);
                        for (int x = k; x < n; x++) g4.set(c[x]);
                        
                        int r1 = g1.count(), r2 = g2.count();
                        int r3 = g3.count(), r4 = g4.count();
                        answer = max(answer, r1 + r2 + r3 + r4);
                    }
                }
            }
        }
        
        cout << answer << ln;
    }

    time();
    return 0;
}