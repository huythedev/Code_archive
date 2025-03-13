// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/110/A
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

bool isLucky(int num) {
    if (num == 0) return false;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

signed main() {
    fastio();
    docfile();

    string n;
    cin >> n;

    int luckyCount = 0;
    for (char c : n) {
        if (c == '4' || c == '7') {
            luckyCount++;
        }
    }

    if (isLucky(luckyCount)) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }

    time();
    return 0;
}