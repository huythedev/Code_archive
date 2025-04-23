// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/158/B

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
    vector<int> groups(n);
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    vector<int> count(5, 0);
    for (int i = 0; i < n; ++i) {
        count[groups[i]]++;
    }

    int taxis = count[4] + count[3] + count[2] / 2;
    count[1] -= count[3];

    if (count[2] % 2 == 1) {
        taxis++;
        count[1] -= 2;
    }

    if (count[1] > 0) {
        taxis += (count[1] + 3) / 4;
    }

    cout << taxis << ln;

    time();
    return 0;
}