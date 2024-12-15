// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2044/problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> b(n);
        b[0] = a[0];
        
        for (int i = 1; i < n; i++) {
            map<int, int> freq;
            freq[a[i]] = 1;
            int target = a[i];
            
            // Count frequencies up to current position
            for (int j = 0; j < i; j++) {
                freq[b[j]]++;
            }
            
            // Find max frequency excluding target
            int max_other = 0;
            for (auto [num, f] : freq) {
                if (num != target) {
                    max_other = max(max_other, f);
                }
            }
            
            if (max_other >= freq[target]) {
                // Need to increase target frequency
                b[i] = target;
            } else {
                // Need unused or low frequency number
                for (int x = 1; x <= n; x++) {
                    if (freq[x] < freq[target]) {
                        b[i] = x;
                        break;
                    }
                }
            }
        }
        
        for (int x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }

    time();
    return 0;
}