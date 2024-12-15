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
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                b[i] = a[i];
                continue;
            }
            
            map<int, int> freq;
            for (int j = 0; j <= i-1; j++) {
                freq[b[j]]++;
            }
            
            int max_freq = 0;
            for (auto [num, f] : freq) {
                max_freq = max(max_freq, f);
            }
            
            if (freq[a[i]] < max_freq) {
                b[i] = a[i];
                continue;
            }
            
            for (int x = 1; x <= n; x++) {
                if (freq[x] <= freq[a[i]] - 1) {
                    b[i] = x;
                    break;
                }
            }
        }
        
        for (int x : b) {
            cout << x << " ";
        }
        cout << ln;
    }

    time();
    return 0;
}