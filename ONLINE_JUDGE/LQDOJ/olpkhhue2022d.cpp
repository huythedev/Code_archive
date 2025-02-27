// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/olpkhhue2022d
// davul
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

int countDivisorsInRange(int m, int left, int right) {
    left = max(left, 1);
    right = min(right, m);
    if (left > right) return 0;
    
    int count = 0;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (i >= left && i <= right) count++;
            int j = m / i;
            if (j != i && j >= left && j <= right) count++;
        }
    }
    return count;
}

int countDivisorsLessThanMInRange(int m, int left, int right) {
    left = max(left, 1);
    right = min(right, m - 1);
    if (left > right) return 0;
    
    int count = 0;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            if (i >= left && i <= right) count++;
            int j = m / i;
            if (j != i && j >= left && j <= right) count++;
        }
    }
    return count;
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
        for (int i = 0; i < n; i++) {
            cin >> ranges[i].first >> ranges[i].second;
            maxR = max(maxR, ranges[i].second);
        }

        ll result = 0;
        
        for (int m = 1; m <= maxR; m++) {
            bool validMax = false;
            for (int i = 0; i < n; i++) {
                if (ranges[i].first <= m && m <= ranges[i].second) {
                    validMax = true;
                    break;
                }
            }
            if (!validMax) continue;

            ll totalWays = 1;
            ll waysWithoutMax = 1;
            
            for (int i = 0; i < n; i++) {
                int countTotal = countDivisorsInRange(m, ranges[i].first, ranges[i].second);
                int countWithoutMax = countDivisorsLessThanMInRange(m, ranges[i].first, ranges[i].second);
                
                totalWays = (totalWays * countTotal) % MOD;
                waysWithoutMax = (waysWithoutMax * countWithoutMax) % MOD;
            }
            
            ll waysWithMax = (totalWays - waysWithoutMax + MOD) % MOD;
            result = (result + waysWithMax) % MOD;
        }

        cout << result << ln;
    }

    time();
    return 0;
}