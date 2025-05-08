// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608263/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

    string s; cin >> s;
    
    int tmp = 0, res = 0;
    
    for(char c : s) {
        if(c == '(') {
            tmp++;
        } else if(tmp > 0) {
            tmp--;
            res++;
        }
    }
    
    cout << 2 * res << ln;

    time();
    return 0;
}