// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/469/A

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
    vector<bool> levels(n + 1, false);

    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int level;
        cin >> level;
        levels[level] = true;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int level;
        cin >> level;
        levels[level] = true;
    }

    bool canBecomeTheGuy = true;
    for (int i = 1; i <= n; ++i) {
        if (!levels[i]) {
            canBecomeTheGuy = false;
            break;
        }
    }

    if (canBecomeTheGuy) {
        cout << "I become the guy." << ln;
    } else {
        cout << "Oh, my keyboard!" << ln;
    }

    time();
    return 0;
}