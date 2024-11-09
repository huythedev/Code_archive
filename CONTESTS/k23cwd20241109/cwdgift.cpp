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

    int n, m; ll d;
    cin >> n >> m >> d;
    
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll maxSum = -1;
    
    for(int i = 0; i < n; i++) {
        int left = 0, right = m - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            ll diff = abs(a[i] - b[mid]);
            
            if(diff <= d) {
                maxSum = max(maxSum, a[i] + b[mid]);
                
                int temp = mid - 1;
                while(temp >= 0 && abs(a[i] - b[temp]) <= d) {
                    maxSum = max(maxSum, a[i] + b[temp]);
                    temp--;
                }
                
                temp = mid + 1;
                while(temp < m && abs(a[i] - b[temp]) <= d) {
                    maxSum = max(maxSum, a[i] + b[temp]);
                    temp++;
                }
                
                break;
            }
            
            if(b[mid] < a[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    cout << maxSum << endl;

    time();
    return 0;
}