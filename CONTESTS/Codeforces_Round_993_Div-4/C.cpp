// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2044/problem/C
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

    int t; cin >> t;
    while (t--) {
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        
        ll row1 = min(a, m);
        ll row2 = min(b, m);
        ll remaining_seats_row1 = m - row1;
        ll remaining_seats_row2 = m - row2;
        
        ll seated_in_row1 = row1 + min(c, remaining_seats_row1);
        ll seated_in_row2 = row2 + min(c - min(c, remaining_seats_row1), remaining_seats_row2);
        
        cout << seated_in_row1 + seated_in_row2 << ln;
    }

    time();
    return 0;
}