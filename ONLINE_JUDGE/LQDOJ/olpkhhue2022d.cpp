// Author: huythedev (https://huythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/olpkhhue2022d

#include <bits/stdc++.h>
using namespace std;

#define NAME "olpkhhue2022d"
#define ln "\n"
#define sz size()
#define MOD 998244353

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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ranges(n);
        int maxR = 0;
        set<int> candidateMaximums;
        
        for (int i = 0; i < n; i++) {
            cin >> ranges[i].first >> ranges[i].second;
            maxR = max(maxR, ranges[i].second);
            
            for (int j = max(1, ranges[i].first); j <= min(ranges[i].second, ranges[i].first + 1); j++) {
                candidateMaximums.insert(j);
            }
            candidateMaximums.insert(ranges[i].second);
        }

        ll result = 0;
        
        for (int m : candidateMaximums) {
            vector<vector<int>> divisors(n);
            
            for (int i = 0; i < n; i++) {
                int left = ranges[i].first;
                int right = ranges[i].second;
                
                for (int d = 1; d * d <= m; d++) {
                    if (m % d == 0) {
                        if (d >= left && d <= right) {
                            divisors[i].push_back(d);
                        }
                        int d2 = m / d;
                        if (d2 != d && d2 >= left && d2 <= right) {
                            divisors[i].push_back(d2);
                        }
                    }
                }
            }
            
            ll totalWays = 1;
            ll waysWithoutMax = 1;
            
            for (int i = 0; i < n; i++) {
                int total = divisors[i].size();
                int withoutMax = 0;
                
                for (int d : divisors[i]) {
                    if (d < m) withoutMax++;
                }
                
                totalWays = (totalWays * total) % MOD;
                waysWithoutMax = (waysWithoutMax * withoutMax) % MOD;
            }
            
            ll waysWithMax = (totalWays - waysWithoutMax + MOD) % MOD;
            result = (result + waysWithMax) % MOD;
        }

        cout << result << ln;
    }

    time();
    return 0;
}