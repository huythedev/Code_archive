// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/155/A
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
    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    int amazing_count = 0;
    int best = scores[0], worst = scores[0];

    for (int i = 1; i < n; ++i) {
        if (scores[i] > best) {
            best = scores[i];
            amazing_count++;
        } else if (scores[i] < worst) {
            worst = scores[i];
            amazing_count++;
        }
    }

    cout << amazing_count << ln;

    time();
    return 0;
}