// Author: huythedev
// Problem Link: https://lqdoj.edu.vn/problem/23qnab2
#include <bits/stdc++.h>
using namespace std;

#define NAME "BIGNUM"
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
    int k; cin >> k;

    string s2;
    for (char c : s) {
        if (isdigit(c)) {
            s2.push_back(c);
        }
    }

    if (s2.length() < k) {
        cout << ln;
    } else {
        string res = "";
        int tmp = s2.length() - k;

        for (char digit : s2) {
            while (!res.empty() && digit > res.back() && tmp > 0) {
                res.pop_back();
                tmp--;
            }
            res.push_back(digit);
        }

        while (res.length() > k) {
            res.pop_back();
        }
        
        cout << res << ln;
    }

    time();
    return 0;
}