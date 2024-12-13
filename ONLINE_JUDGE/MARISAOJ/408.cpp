// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/408
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

    int k, n; cin >> k >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    while(k--) {
        a.push_back(a[0]);
        a.erase(a.begin());
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    time();
    return 0;
}