// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/595363/problem/D
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

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s += c;
    }
    
    int l = 0, r = n - 1;
    string res = "";
    
    while (l <= r) {
        bool choose = true; 
        
        for (int i = 0; l + i < r - i; i++) { 
            if (s[l + i] < s[r - i]) {
                choose = true;
                break;
            } 
            else if (s[l + i] > s[r - i]) {
                choose = false;
                break;
            }
        }
        
        if (choose) res += s[l++];
        else res += s[r--];
    }
    
    for (int i = 0; i < res.sz; i++) {
        cout << res[i];
        if (i % 80 == 79) cout << ln;
    }

    time();
    return 0;
}