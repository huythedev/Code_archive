// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "date"
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

bool is_leap(int y) {
    if (y == 0) return false;
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int days_in_month(int m, int y) {
    if (m < 1 || m > 12 || y == 0) return 0;
    if (m == 2) {
        return is_leap(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

void solve() {
    string day, month, year; cin >> day >> month >> year;

    string s = day + month + year;
    
    vector<int> p(8);
    for (int i = 0; i < 8; ++i) {
        p[i] = s[i] - '0';
    }
    sort(p.begin(), p.end());

    set<tuple<int, int, int>> st;

    do {
        int d = p[0] * 10 + p[1];
        int m = p[2] * 10 + p[3];
        int y = p[4] * 1000 + p[5] * 100 + p[6] * 10 + p[7];

        if (d >= 1 && d <= days_in_month(m, y)) 
            st.insert({y, m, d});

    } while (next_permutation(p.begin(), p.end()));

    if (st.empty()) 
        cout << 0 << ln;
    else {
        cout << st.size() << " ";
        auto it = *st.begin();
        cout << setfill('0') << setw(2) << get<2>(it) << " ";
        cout << setfill('0') << setw(2) << get<1>(it) << " ";
        cout << setfill('0') << setw(4) << get<0>(it) << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}