// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/151/A
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

    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int total_drink = k * l;
    int total_limes = c * d;
    int total_salt = p;

    int drink_per_person = total_drink / nl;
    int lime_per_person = total_limes;
    int salt_per_person = total_salt / np;

    int toasts = min({drink_per_person, lime_per_person, salt_per_person}) / n;

    cout << toasts << ln;

    time();
    return 0;
}