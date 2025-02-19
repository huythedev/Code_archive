// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/hoaban1
#include <bits/stdc++.h>
using namespace std;

#define NAME "hoaban1"
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
    int n, q; ll B; cin >> n >> q >> B;
    
    vector<ll> height(n + 1, B);
    
    for(int i = 0; i < q; i++) {
        int r, p; cin >> r >> p;
        
        while(p--) {
            int minIdx = 1;
            for(int j = 2; j <= r; j++) {
                if(height[j] < height[minIdx]) {
                    minIdx = j;
                }
            }
            height[minIdx]++;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << height[i] << " ";
    }
}

int main() {
    fastio();
    docfile();

    solve();

    time();
    return 0;
}