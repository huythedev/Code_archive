// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6ancient
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6ancient"
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

ll getBeauty(const vector<ll>& arr) {
    ll beauty = 0;
    for (int i = 1; i < arr.size(); i++) {
        beauty += abs(arr[i] - arr[i-1]);
    }
    return beauty;
}

ll type2(const vector<ll>& arr) {
    int n = arr.size();
    ll maxBeauty = getBeauty(arr);
    
    for (int l = 0; l < n-1; l++) {
        for (int r = l+1; r < n; r++) {
            vector<ll> rotated = arr;
            
            rotated[l] = arr[r];
            for (int i = l+1; i <= r; i++) {
                rotated[i] = arr[i-1];
            }
            
            maxBeauty = max(maxBeauty, getBeauty(rotated));
        }
    }
    
    return maxBeauty;
}

int main() {
    fastio();
    docfile();

    int n, q;
    cin >> n >> q;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < q; i++) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int idx;
            ll val;
            cin >> idx >> val;
            arr[idx-1] = val; 
        } 
        else {
            cout << type2(arr) << ln;
        }
    }

    time();
    return 0;
}