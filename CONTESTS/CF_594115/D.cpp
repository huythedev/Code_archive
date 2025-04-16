// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/D
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

int units, target;
vector <int> money_units (25);

signed main() {
    fastio();
    docfile();

    cin >> units >> target;
    money_units.resize(units);
    for (int i = 0; i < units; ++i) cin >> money_units[i];

    vector <ll> dp (target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < units; ++i) {
        for (int j = money_units[i]; j <= target; ++j) {
            dp[j] += dp[j - money_units[i]];
        }
    }

    cout << dp[target] << ln;

    time();
    return 0;
}