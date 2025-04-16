`// Author: huythedev (https://huythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DAYCON"
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
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    unordered_map<ll, int> mp;  
    ll sum = 0;
    int res = 0;
    mp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
        res += mp[sum - (i + 1)];
        mp[sum - (i + 1)]++;       
    }
    
    cout << res;
    
    time();
    return 0;
}