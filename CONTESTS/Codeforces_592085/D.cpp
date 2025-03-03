// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/gym/592085/problem/D
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

    int n, k; cin >> n >> k;
    
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    sort(t.begin(), t.end());
    
    int tong = t[n-1] + 1 - t[0];
    
    vector<int> vec;
    for(int i = 1; i < n; i++) {
        int gap = t[i] - (t[i-1] + 1);
        if(gap > 0) { 
            vec.push_back(gap);
        }
    }
    
    sort(vec.begin(), vec.end(), greater<int>());
    
    int tmp = 0;
    for(int i = 0; i < min(k-1, (int)vec.size()); i++) {
        tmp += vec[i];
    }
    
    int res = tong - tmp;
    
    cout << res << ln;

    time();
    return 0;
}