// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/208/A

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

    string result;
    bool space = false;

    for (size_t i = 0; i < s.sz; ++i) {
        if (i + 2 < s.sz && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            if (!result.empty() && !space) {
                result += ' ';
                space = true;
            }
            i += 2;
        } else {
            result += s[i];
            space = false;
        }
    }

    cout << result << ln;

    time();
    return 0;
}