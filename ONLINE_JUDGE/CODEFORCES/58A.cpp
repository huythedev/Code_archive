// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/58/A
// davul
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

signed main() {
    fastio();
    docfile();

    string s;
    cin >> s;
    string target = "hello";
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == target[j]) {
            j++;
        }
        if (j == target.size()) {
            cout << "YES" << ln;
            time();
            return 0;
        }
    }

    cout << "NO" << ln;
    
    time();
    return 0;
}