// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/25/A
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
    vector<int> numbers(n);
    vector<int> even_indices, odd_indices;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        if (numbers[i] % 2 == 0) {
            even_indices.push_back(i + 1);
        } else {
            odd_indices.push_back(i + 1);
        }
    }

    if (even_indices.size() == 1) {
        cout << even_indices[0] << ln;
    } else {
        cout << odd_indices[0] << ln;
    }

    time();
    return 0;
}