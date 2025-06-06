// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/230/A

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
struct Dragon {
    int strength;
    int bonus;
};

bool compareDragons(Dragon a, Dragon b) {
    return a.strength < b.strength;
}

signed main() {
    fastio();
    docfile();

    int s, n;
    cin >> s >> n;
    vector<Dragon> dragons(n);

    for (int i = 0; i < n; ++i) {
        cin >> dragons[i].strength >> dragons[i].bonus;
    }

    sort(dragons.begin(), dragons.end(), compareDragons);

    for (int i = 0; i < n; ++i) {
        if (s > dragons[i].strength) {
            s += dragons[i].bonus;
        } else {
            cout << "NO" << ln;
            time();
            return 0;
        }
    }

    cout << "YES" << ln;

    time();
    return 0;
}