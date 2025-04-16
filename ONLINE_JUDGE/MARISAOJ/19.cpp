// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/19
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

    string s; cin >> s;
    int res = 0;
    if(s[0] == '-') {
        s.erase(0, 1);
    }

    for(char c : s)
        res += (c - '0');

    cout << res;

    time();
    return 0;
}