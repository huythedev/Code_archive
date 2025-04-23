// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vku.udn.vn/problem/olp6magicstones

#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6magicstones"
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

    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        r[i]--; 
    }

    bool tmp = true;
    for (int i = 0; i < n; ++i) {
        if (r[i] != i) {
            tmp = false;
            break;
        }
    }

    if (tmp) {
        cout << 1;
        return 0;
    }

    ll res = 1;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cue = i;
            ll tmp2 = 0;

            while (!visited[cue]) {
                visited[cue] = true;
                cue = r[cue];
                tmp2++;
            }

            res = lcm(res, tmp2);
        }
    }

    cout << res;
    time();
    return 0;
}