// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/144/A
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
    vector<int> soldiers(n);
    for (int i = 0; i < n; ++i) {
        cin >> soldiers[i];
    }

    int max_index = 0, min_index = 0;
    for (int i = 1; i < n; ++i) {
        if (soldiers[i] > soldiers[max_index]) {
            max_index = i;
        }
        if (soldiers[i] <= soldiers[min_index]) {
            min_index = i;
        }
    }

    int result = max_index + (n - 1 - min_index);
    if (max_index > min_index) {
        result--;
    }

    cout << result << ln;

    time();
    return 0;
}