// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/538
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

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> neg, pos;
    for (int x : a) {
        if (x < 0) neg.push_back(x);
        else pos.push_back(x);
    }

    for (int x : neg) cout << x << ' ';
    for (int x : pos) cout << x << ' ';

    time();
    return 0;
}