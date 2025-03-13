// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/32/B
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
    string result = "";
    for (size_t i = 0; i < s.sz; ++i) {
        if (s[i] == '.') {
            result += '0';
        } else if (s[i] == '-' && s[i + 1] == '.') {
            result += '1';
            ++i;
        } else if (s[i] == '-' && s[i + 1] == '-') {
            result += '2';
            ++i;
        }
    }
    cout << result << ln;

    time();
    return 0;
}