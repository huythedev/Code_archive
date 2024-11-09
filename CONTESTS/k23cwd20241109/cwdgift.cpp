// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/cwdgift
#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdgift"
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

    int n, m; ll d; cin >> n >> m >> d;
    
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll res = -1;
    
    for(int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            ll diff = abs(a[i] - b[mid]);
            
            if(diff <= d) {
                res = max(res, a[i] + b[mid]);
                
                int tmp = mid - 1;
                while(tmp >= 0 && abs(a[i] - b[tmp]) <= d) {
                    res = max(res, a[i] + b[tmp]);
                    tmp--;
                }
                
                tmp = mid + 1;
                while(tmp < m && abs(a[i] - b[tmp]) <= d) {
                    res = max(res, a[i] + b[tmp]);
                    tmp++;
                }
                
                break;
            }
            
            if(b[mid] < a[i]) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
    }
    
    cout << res;

    time();
    return 0;
}