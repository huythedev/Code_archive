// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/31
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

    int second_max = INT_MIN, max_val = INT_MIN;
    for (int x : a) {
        if (x > max_val) {
            second_max = max_val;
            max_val = x;
        } else if (x > second_max) {
            second_max = x;
        }
    }

    cout << second_max;

    time();
    return 0;
}