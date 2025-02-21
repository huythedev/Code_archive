// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/elaina_kstb24_dangnhap
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "DANGNHAP"
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

bool can_extract_login(const string &s) {
    string target = "login";
    int j = 0;
    for (char c : s) {
        if (c == target[j]) {
            j++;
            if (j == target.size()) return true;
        }
    }
    return false;
}


int main() {
    fastio();
    docfile();

    int tests; cin >> tests;
    int res = 0;
    vector<int> ans;
    int idx = 0;
    while (tests--) {
        string s; cin >> s;
        if (can_extract_login(s)) {
            ++res;
            ans.push_back(idx);
        }
        ++idx;
    }

    cout << res << ln;
    for (int x : ans) {
        cout << x + 1 << ' ';
    }

    time();
    return 0;
}