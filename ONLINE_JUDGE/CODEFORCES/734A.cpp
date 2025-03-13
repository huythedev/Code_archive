// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/734/A
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

    int n;
    cin >> n;
    string s;
    cin >> s;

    int antonWins = 0, danikWins = 0;
    for (char c : s) {
        if (c == 'A') antonWins++;
        else if (c == 'D') danikWins++;
    }

    if (antonWins > danikWins) cout << "Anton" << ln;
    else if (danikWins > antonWins) cout << "Danik" << ln;
    else cout << "Friendship" << ln;

    time();
    return 0;
}